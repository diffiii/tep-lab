#ifndef MUL_H
#define MUL_H

#include "operators/operator.h"

namespace nodes
{
  class Mul final : public Operator
  {
    Result<double, Error> eval() const override;
    std::string repr() const override;
  };
}

#endif
