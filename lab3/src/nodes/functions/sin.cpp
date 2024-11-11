#include "nodes/functions/sin.h"

#include <cmath>

namespace nodes
{
  double Sin::eval() const
  {
    return sin(this->getChild(0)->eval());
  }

  std::string Sin::repr() const
  {
    return "sin " + this->getChild(0)->repr();
  }
}
