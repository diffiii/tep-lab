#include "numbers/const.h"

namespace nodes
{
  Const::Const()
  {
    this->value = CONST_DEFAULT_VALUE;
  }

  Const::Const(const uint8_t value)
  {
    this->value = value;
  }

  Result<double, Error> Const::eval() const
  {
    return Result<double, Error>::ok(this->value);
  }

  std::string Const::repr() const
  {
    return std::to_string(this->value);
  }
}
