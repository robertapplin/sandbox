// Mantid Repository : https://github.com/mantidproject/mantid
//
// Copyright &copy; 2024 ISIS Rutherford Appleton Laboratory UKRI,
//   NScD Oak Ridge National Laboratory, European Spallation Source,
//   Institut Laue - Langevin & CSNS, Institute of High Energy Physics, CAS
// SPDX - License - Identifier: GPL - 3.0 +
#include "PollModel.h"
#include "PollView.h"
#include "PollPresenter.h"

#include <QApplication>


int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  auto model = std::make_unique<PollModel>();
  auto view = new PollView();
  auto presenter = std::make_unique<PollPresenter>(std::move(model), view);

  view->show();

  return app.exec();
}