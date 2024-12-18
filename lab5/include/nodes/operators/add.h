#ifndef ADD_H
#define ADD_H

#include "operators/operator.h"

namespace nodes
{
  class Add final : public Operator
  {
    Result<double, Error> eval() const override;
    std::string repr() const override;
  };
}

#endif
