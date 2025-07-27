// Mantid Repository : https://github.com/mantidproject/mantid
//
// Copyright &copy; 2024 ISIS Rutherford Appleton Laboratory UKRI,
//   NScD Oak Ridge National Laboratory, European Spallation Source,
//   Institut Laue - Langevin & CSNS, Institute of High Energy Physics, CAS
// SPDX - License - Identifier: GPL - 3.0 +
#include "InvokeModel.h"


InvokeModel::InvokeModel() : m_count(0u) {}

std::size_t InvokeModel::count() const {
  return m_count;
}

void InvokeModel::setCount(std::size_t const value) {
  m_count = value;
}
