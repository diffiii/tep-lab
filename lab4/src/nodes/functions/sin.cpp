#include "functions/sin.h"

#include <cmath>

namespace nodes
{
  Result<double, Error> Sin::eval() const
  {
    const Result<double, Error> childEval = this->getChild(0)->eval();

    if (childEval.isFailure())
    {
      std::vector<Error*> errors = childEval.getErrors();
      return Result<double, Error>::fail(errors);
    }

    return Result<double, Error>::ok(sin(childEval.getValue()));
  }

  std::string Sin::repr() const
  {
    return "sin " + this->getChild(0)->repr();
  }
}
