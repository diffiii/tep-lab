#ifndef MUL_H
#define MUL_H

#include "nodes/operators/operator.h"

namespace nodes
{
  class Mul final : public Operator
  {
  public:
    double eval() const override;
    std::string repr() const override;
  };
}

#endif
