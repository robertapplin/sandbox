// Mantid Repository : https://github.com/mantidproject/mantid
//
// Copyright &copy; 2024 ISIS Rutherford Appleton Laboratory UKRI,
//   NScD Oak Ridge National Laboratory, European Spallation Source,
//   Institut Laue - Langevin & CSNS, Institute of High Energy Physics, CAS
// SPDX - License - Identifier: GPL - 3.0 +
#include "PollModel.h"


PollModel::PollModel() : m_count(0u) {}

std::size_t PollModel::count() const {
  return m_count;
}

void PollModel::setCount(std::size_t const value) {
  m_count = value;
}
