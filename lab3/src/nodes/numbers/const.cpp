#include "nodes/numbers/const.h"

namespace nodes
{
  Const::Const()
  {
    this->value = 0;
  }

  Const::Const(const uint8_t value)
  {
    this->value = value;
  }

  double Const::eval() const
  {
    return this->value;
  }

  std::string Const::repr() const
  {
    return std::string {static_cast<char>(this->value + '0')};
  }
}
