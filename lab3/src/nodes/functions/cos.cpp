#include "nodes/functions/cos.h"

#include <cmath>

namespace nodes
{
  double Cos::eval() const
  {
    return cos(this->getChild(0)->eval());
  }

  std::string Cos::repr() const
  {
    return "cos " + this->getChild(0)->repr();
  }
}
