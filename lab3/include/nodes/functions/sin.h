#ifndef SIN_H
#define SIN_H

#include "nodes/functions/function.h"

namespace nodes
{
  class Sin final : public Function
  {
  public:
    double eval() const override;
    std::string repr() const override;
  };
}

#endif
