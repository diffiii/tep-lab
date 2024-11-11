#ifndef COS_H
#define COS_H

#include "nodes/functions/function.h"

namespace nodes
{
  class Cos final : public Function
  {
  public:
    double eval() const override;
    std::string repr() const override;
  };
}

#endif
