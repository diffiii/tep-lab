#include "nodes/operators/add.h"

namespace nodes
{
  double Add::eval() const
  {
    return this->getChild( 0 )->eval()
         + this->getChild( 1 )->eval();
  }

  std::string Add::repr() const
  {
    return "+ " + this->getChild( 0 )->repr()
          + " " + this->getChild( 1 )->repr();
  }
}
