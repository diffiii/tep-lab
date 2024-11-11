#include "nodes/operators/mul.h"

namespace nodes
{
  double Mul::eval() const
  {
    return this->getChild( 0 )->eval()
         * this->getChild( 1 )->eval();
  }

  std::string Mul::repr() const
  {
    return "* " + this->getChild( 0 )->repr()
          + " " + this->getChild( 1 )->repr();
  }
}
