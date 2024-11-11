#ifndef CONST_H
#define CONST_H

#include "nodes/numbers/number.h"

namespace nodes
{
  class Const final : public Number
  {
  public:
    Const();
    explicit Const(uint8_t value);
    double eval() const override;
    std::string repr() const override;

  private:
    uint8_t value;
  };
}

#endif
