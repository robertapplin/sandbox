// Mantid Repository : https://github.com/mantidproject/mantid
//
// Copyright &copy; 2024 ISIS Rutherford Appleton Laboratory UKRI,
//   NScD Oak Ridge National Laboratory, European Spallation Source,
//   Institut Laue - Langevin & CSNS, Institute of High Energy Physics, CAS
// SPDX - License - Identifier: GPL - 3.0 +
#include "InvokeView.h"

#include "InvokePresenter.h"

#include <string>

#include <QLabel>
#include <QMetaObject>
#include <QMetaType>
#include <QString>

Q_DECLARE_METATYPE(std::string);


InvokeView::InvokeView(QWidget *parent) : QWidget(parent), m_presenter() {
  m_uiForm.setupUi(this);

  qRegisterMetaType<std::string>("std::string");

  connect(m_uiForm.pbIncrement, &QPushButton::clicked, this, &InvokeView::notifyButtonClicked);
}

void InvokeView::subscribe(IInvokePresenter *presenter) {
  m_presenter = presenter;
}

void InvokeView::notifyButtonClicked() {
  // An example event slot which notifies the presenter
  m_presenter->handleButtonClicked();
}

void InvokeView::invokeAddLabel(std::string const &text) {
  QMetaObject::invokeMethod(this, "addLabel", Q_ARG(std::string, text));
}

void InvokeView::addLabel(std::string text) {
  this->layout()->addWidget(new QLabel(QString::fromStdString(text)));
}
