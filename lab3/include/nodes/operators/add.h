#ifndef ADD_H
#define ADD_H

#include "nodes/operators/operator.h"

namespace nodes
{
  class Add final : public Operator
  {
  public:
    double eval() const override;
    std::string repr() const override;
  };
}

#endif
