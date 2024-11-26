#include "operators/sub.h"

namespace nodes
{
  Result<double, Error> Sub::eval() const
  {
    const Result<double, Error> leftEval = this->getChild(0)->eval();

    if (leftEval.isFailure())
    {
      std::vector<Error*> errors = leftEval.getErrors();
      return Result<double, Error>::fail(errors);
    }

    const Result<double, Error> rightEval = this->getChild(1)->eval();

    if (rightEval.isFailure())
    {
      std::vector<Error*> errors = rightEval.getErrors();
      return Result<double, Error>::fail(errors);
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
