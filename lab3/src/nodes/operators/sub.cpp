#include "nodes/operators/sub.h"

namespace nodes
{
  double Sub::eval() const
  {
    return this->getChild( 0 )->eval()
         - this->getChild( 1 )->eval();
  }

  std::string Sub::repr() const
  {
    return "- " + this->getChild( 0 )->repr()
          + " " + this->getChild( 1 )->repr();
  }
}
