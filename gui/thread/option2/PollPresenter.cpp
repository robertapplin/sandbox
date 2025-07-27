// Mantid Repository : https://github.com/mantidproject/mantid
//
// Copyright &copy; 2024 ISIS Rutherford Appleton Laboratory UKRI,
//   NScD Oak Ridge National Laboratory, European Spallation Source,
//   Institut Laue - Langevin & CSNS, Institute of High Energy Physics, CAS
// SPDX - License - Identifier: GPL - 3.0 +
#include "PollPresenter.h"

#include "PollModel.h"
#include "PollView.h"

#include <thread>

PollPresenter::PollPresenter(std::unique_ptr<IPollModel> model, IPollView *view) : m_model(std::move(model)), m_view(view),
  m_backgroundThread(), m_threadStarted(false) {
  // Use a subscriber to avoid Qt connections in the presenter
  m_view->subscribe(this);
}

PollPresenter::~PollPresenter() {
  if (m_threadStarted && m_backgroundThread.joinable()) {
    m_backgroundThread.join();
  }
}

void PollPresenter::handleButtonClicked() {
  // An example method to handle a view event

  if (m_threadStarted && m_backgroundThread.joinable()) {
    m_backgroundThread.join();
  }

  m_threadStarted = true;
  m_backgroundThread = std::thread(&PollPresenter::run, this);
}

void PollPresenter::run() {
  // Do intense processing
  m_model->setCount(m_model->count() + 1u);
}

void PollPresenter::poll() {
  // Call view method from GUI thread
  m_view->addLabel(std::to_string(m_model->count()));
}
