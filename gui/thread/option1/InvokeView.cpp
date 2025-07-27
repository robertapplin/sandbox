// Mantid Repository : https://github.com/mantidproject/mantid
//
// Copyright &copy; 2024 ISIS Rutherford Appleton Laboratory UKRI,
//   NScD Oak Ridge National Laboratory, European Spallation Source,
//   Institut Laue - Langevin & CSNS, Institute of High Energy Physics, CAS
// SPDX - License - Identifier: GPL - 3.0 +
#include "InvokeView.h"

#include "InvokePresenter.h"

#include <string>
#include <QString>


InvokeView::InvokeView(QWidget *parent) : QWidget(parent), m_presenter() {
  m_uiForm.setupUi(this);

  connect(m_uiForm.pbIncrement, &QPushButton::clicked, this, &InvokeView::notifyButtonClicked);
}

void InvokeView::subscribe(IInvokePresenter *presenter) {
  m_presenter = presenter;
}

void InvokeView::notifyButtonClicked() {
  // An example event slot which notifies the presenter
  m_presenter->handleButtonClicked();
}

void InvokeView::setLabel(std::string const &text) {
  m_uiForm.lbCount->setText(QString::fromStdString(text));
}
