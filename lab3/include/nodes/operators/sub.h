#ifndef SUB_H
#define SUB_H

#include "nodes/operators/operator.h"

namespace nodes
{
  class Sub final : public Operator
  {
  public:
    double eval() const override;
    std::string repr() const override;
  };
}

#endif
