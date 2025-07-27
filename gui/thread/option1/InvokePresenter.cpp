// Mantid Repository : https://github.com/mantidproject/mantid
//
// Copyright &copy; 2024 ISIS Rutherford Appleton Laboratory UKRI,
//   NScD Oak Ridge National Laboratory, European Spallation Source,
//   Institut Laue - Langevin & CSNS, Institute of High Energy Physics, CAS
// SPDX - License - Identifier: GPL - 3.0 +
#include "InvokePresenter.h"

#include "InvokeModel.h"
#include "InvokeView.h"

#include <thread>

InvokePresenter::InvokePresenter(std::unique_ptr<IInvokeModel> model, IInvokeView *view) : m_model(std::move(model)), m_view(view),
 m_backgroundThread(), m_threadStarted(false) {
  // Use a subscriber to avoid Qt connections in the presenter
  m_view->subscribe(this);
}

InvokePresenter::~InvokePresenter() {
  if (m_threadStarted && m_backgroundThread.joinable()) {
    m_backgroundThread.join();
  }
}

void InvokePresenter::handleButtonClicked() {
  // An example method to handle a view event

  if (m_threadStarted && m_backgroundThread.joinable()) {
    m_backgroundThread.join();
  }

  m_threadStarted = true;
  m_backgroundThread = std::thread(&InvokePresenter::run, this);
}

void InvokePresenter::run() {
  // Do intense processing
  m_model->setCount(m_model->count() + 1u);

  // Call view method from a non-GUI thread
  m_view->invokeAddLabel(std::to_string(m_model->count()));
}