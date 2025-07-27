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


class IPollView;

class IPollPresenter {
public:
  virtual ~IPollPresenter() = default;

  virtual void handleButtonClicked() = 0;
};

class PollPresenter final : public IPollPresenter {

public:
  PollPresenter(std::unique_ptr<IPollModel> model, IPollView *view);
  ~PollPresenter() override = default;

  void handleButtonClicked() override;

private:
  std::unique_ptr<IPollModel> m_model;
  IPollView *m_view;
};
