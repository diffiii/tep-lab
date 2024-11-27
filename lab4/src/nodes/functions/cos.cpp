#include "functions/cos.h"

#include <cmath>

namespace nodes
{
  Result<double, Error> Cos::eval() const
  {
    const Result<double, Error> childEval = this->getChild(0)->eval();

    if (childEval.isFailure())
    {
      return Result<double, Error>::fail(childEval.getErrors());
    }

    return Result<double, Error>::ok(cos(childEval.getValue()));
  }

  std::string Cos::repr() const
  {
    return "cos " + this->getChild(0)->repr();
  }
}
