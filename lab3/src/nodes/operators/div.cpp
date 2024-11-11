#include "nodes/operators/div.h"

namespace nodes
{
  double Div::eval() const
  {
    return this->getChild( 0 )->eval()
         / this->getChild( 1 )->eval();
  }

  std::string Div::repr() const
  {
    return "/ " + this->getChild( 0 )->repr()
          + " " + this->getChild( 1 )->repr();
  }
}