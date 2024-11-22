#include "nodes/operators/div.h"

#include "cli.h"

namespace nodes
{
  double Div::eval() const
  {
    if (this->getChild( 1 )->eval() == 0)
    {
      CLI::printInfo(DIVISION_BY_ZERO);
      return 0.0;
    }

    return this->getChild( 0 )->eval()
         / this->getChild( 1 )->eval();
  }

  std::string Div::repr() const
  {
    return "/ " + this->getChild( 0 )->repr()
          + " " + this->getChild( 1 )->repr();
  }
}
