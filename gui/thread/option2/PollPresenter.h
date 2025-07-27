// Mantid Repository : https://github.com/mantidproject/mantid
//
// Copyright &copy; 2024 ISIS Rutherford Appleton Laboratory UKRI,
//   NScD Oak Ridge National Laboratory, European Spallation Source,
//   Institut Laue - Langevin & CSNS, Institute of High Energy Physics, CAS
// SPDX - License - Identifier: GPL - 3.0 +
#pragma once

#include "PollModel.h"

#include <string>
#include <memory>
#include <thread>


class IPollView;

class IPollPresenter {
public:
  virtual ~IPollPresenter() = default;

  virtual void handleButtonClicked() = 0;

  virtual void poll() = 0;
};

class PollPresenter final : public IPollPresenter {

public:
  PollPresenter(std::unique_ptr<IPollModel> model, IPollView *view);
  ~PollPresenter() override;

  void handleButtonClicked() override;

  void poll() override;

private:
  void run();

  std::unique_ptr<IPollModel> m_model;
  IPollView *m_view;

  std::thread m_backgroundThread;
  bool m_threadStarted;
};
