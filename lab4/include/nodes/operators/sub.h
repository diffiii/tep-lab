#ifndef SUB_H
#define SUB_H

#include "operators/operator.h"

namespace nodes
{
  class Sub final : public Operator
  {
    Result<double, Error> eval() const override;
    std::string repr() const override;
  };
}

#endif
