#ifndef DIV_H
#define DIV_H

#include "operators/operator.h"

static const std::string DIVISION_BY_ZERO_ERROR_MESSAGE =
  "Division by zero";

namespace nodes
{
  class Div final : public Operator
  {
    Result<double, Error> eval() const override;
    std::string repr() const override;
  };
}

#endif
