// Mantid Repository : https://github.com/mantidproject/mantid
//
// Copyright &copy; 2024 ISIS Rutherford Appleton Laboratory UKRI,
//   NScD Oak Ridge National Laboratory, European Spallation Source,
//   Institut Laue - Langevin & CSNS, Institute of High Energy Physics, CAS
// SPDX - License - Identifier: GPL - 3.0 +
#pragma once

#include <string>
#include "ui_InvokeGUIWidget.h"

#include <QObject>
#include <QWidget>


class IInvokePresenter;

class IInvokeView {
public:
  virtual ~IInvokeView() = default;

  virtual void subscribe(IInvokePresenter *presenter) = 0;

  virtual void setLabel(std::string const &text) = 0;
};

class InvokeView final : public QWidget, public IInvokeView {
  Q_OBJECT

public:
  InvokeView(QWidget *parent = nullptr);
  ~InvokeView() override = default;

  void subscribe(IInvokePresenter *presenter) override;

  void setLabel(std::string const &text) override;

private slots:
  void notifyButtonClicked();

private:
  Ui::InvokeGUIWidget m_uiForm;

  IInvokePresenter *m_presenter;
};
