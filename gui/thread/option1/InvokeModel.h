// Mantid Repository : https://github.com/mantidproject/mantid
//
// Copyright &copy; 2024 ISIS Rutherford Appleton Laboratory UKRI,
//   NScD Oak Ridge National Laboratory, European Spallation Source,
//   Institut Laue - Langevin & CSNS, Institute of High Energy Physics, CAS
// SPDX - License - Identifier: GPL - 3.0 +
#pragma once

#include <string>
#include <cstddef>


class IInvokeModel {
public:
  virtual ~IInvokeModel() = default;

  virtual std::size_t count() const = 0;

  virtual void setCount(std::size_t const value) = 0;
};

class InvokeModel final : public IInvokeModel {

public:
  InvokeModel();
  ~InvokeModel() override = default;

  std::size_t count() const override;

  void setCount(std::size_t const value) override;

private:
  std::size_t m_count;
};
