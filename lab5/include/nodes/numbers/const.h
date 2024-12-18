#ifndef CONST_H
#define CONST_H

#include "numbers/number.h"

static const uint8_t CONST_DEFAULT_VALUE = 0;

namespace nodes
{
  class Const final : public Number
  {
  public:
    Const();
    Const(uint8_t value);
    Result<double, Error> eval() const override;
    std::string repr() const override;

  private:
    uint8_t value;
  };
}

#endif
