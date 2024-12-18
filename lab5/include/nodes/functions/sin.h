#ifndef SIN_H
#define SIN_H

#include "functions/function.h"

namespace nodes
{
  class Sin final : public Function
  {
  public:
    Result<double, Error> eval() const override;
    std::string repr() const override;
  };
}

#endif
