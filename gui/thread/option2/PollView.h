// Mantid Repository : https://github.com/mantidproject/mantid
//
// Copyright &copy; 2024 ISIS Rutherford Appleton Laboratory UKRI,
//   NScD Oak Ridge National Laboratory, European Spallation Source,
//   Institut Laue - Langevin & CSNS, Institute of High Energy Physics, CAS
// SPDX - License - Identifier: GPL - 3.0 +
#pragma once

#include <string>
#include "ui_PollGUIWidget.h"

#include <QObject>
#include <QWidget>


class IPollPresenter;

class IPollView {
public:
  virtual ~IPollView() = default;

  virtual void subscribe(IPollPresenter *presenter) = 0;

  virtual void setLabel(std::string const &text) = 0;
};

class PollView final : public QWidget, public IPollView {
  Q_OBJECT

public:
  PollView(QWidget *parent = nullptr);
  ~PollView() override = default;

  void subscribe(IPollPresenter *presenter) override;

  void setLabel(std::string const &text) override;

private slots:
  void notifyButtonClicked();

private:
  Ui::PollGUIWidget m_uiForm;

  IPollPresenter *m_presenter;
};
