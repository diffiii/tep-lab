#ifndef DIV_H
#define DIV_H

#include "nodes/operators/operator.h"

namespace nodes
{
  class Div final : public Operator
  {
  public:
    double eval() const override;
    std::string repr() const override;
  };
}

#endif
