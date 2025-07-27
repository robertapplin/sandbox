// Mantid Repository : https://github.com/mantidproject/mantid
//
// Copyright &copy; 2024 ISIS Rutherford Appleton Laboratory UKRI,
//   NScD Oak Ridge National Laboratory, European Spallation Source,
//   Institut Laue - Langevin & CSNS, Institute of High Energy Physics, CAS
// SPDX - License - Identifier: GPL - 3.0 +
#include "PollView.h"

#include "PollPresenter.h"

#include <string>

#include <QEvent>
#include <QLabel>
#include <QString>

PollView::PollView(QWidget *parent) : QWidget(parent), m_presenter() {
  m_uiForm.setupUi(this);

  connect(m_uiForm.pbIncrement, &QPushButton::clicked, this, &PollView::notifyButtonClicked);
}

void PollView::subscribe(IPollPresenter *presenter) {
  m_presenter = presenter;
}

void PollView::notifyButtonClicked() {
  // An example event slot which notifies the presenter
  m_presenter->handleButtonClicked();
}

bool PollView::event(QEvent* event) {
  if (event->type() == QEvent::MouseButtonRelease) {
    // Poll from the GUI thread
    if (m_presenter) {
      m_presenter->poll();
    }
  }

  return QWidget::event(event);
}

void PollView::addLabel(std::string const &text) {
  this->layout()->addWidget(new QLabel(QString::fromStdString(text)));
}
