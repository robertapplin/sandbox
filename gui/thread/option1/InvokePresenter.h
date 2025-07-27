// Mantid Repository : https://github.com/mantidproject/mantid
//
// Copyright &copy; 2024 ISIS Rutherford Appleton Laboratory UKRI,
//   NScD Oak Ridge National Laboratory, European Spallation Source,
//   Institut Laue - Langevin & CSNS, Institute of High Energy Physics, CAS
// SPDX - License - Identifier: GPL - 3.0 +
#pragma once

#include "InvokeModel.h"

#include <string>
#include <memory>
#include <thread>


class IInvokeView;

class IInvokePresenter {
public:
  virtual ~IInvokePresenter() = default;

  virtual void handleButtonClicked() = 0;
};

class InvokePresenter final : public IInvokePresenter {

public:
  InvokePresenter(std::unique_ptr<IInvokeModel> model, IInvokeView *view);
  ~InvokePresenter() override;

  void handleButtonClicked() override;

private:
  void run();

  std::unique_ptr<IInvokeModel> m_model;
  IInvokeView *m_view;

  std::thread m_backgroundThread;
  bool m_threadStarted;
};
