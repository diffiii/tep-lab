#ifndef COS_H
#define COS_H

#include "functions/function.h"

namespace nodes
{
  class Cos final : public Function
  {
  public:
    Result<double, Error> eval() const override;
    std::string repr() const override;
  };
}

#endif
