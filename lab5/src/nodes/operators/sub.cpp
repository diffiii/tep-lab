#include "operators/sub.h"

namespace nodes
{
  Result<double, Error> Sub::eval() const
  {
    const Result<double, Error> leftEval = this->getChild(0)->eval();

    if (leftEval.isFailure())
    {
      return Result<double, Error>::fail(leftEval.getErrors());
    }

    const Result<double, Error> rightEval = this->getChild(1)->eval();

    if (rightEval.isFailure())
    {
      return Result<double, Error>::fail(rightEval.getErrors());
    }

    return Result<double, Error>::ok(
      leftEval.getValue() - rightEval.getValue()
    );
  }

  std::string Sub::repr() const
  {
    return "- " + this->getChild(0)->repr()
          + " " + this->getChild(1)->repr();
  }
}
