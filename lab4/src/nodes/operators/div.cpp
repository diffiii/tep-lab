#include "operators/div.h"

namespace nodes
{
  Result<double, Error> Div::eval() const
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

    if (rightEval.getValue() == 0)
    {
      return Result<double, Error>::fail(
        new Error(DIVISION_BY_ZERO_ERROR_MESSAGE)
      );
    }

    return Result<double, Error>::ok(
      leftEval.getValue() / rightEval.getValue()
    );
  }

  std::string Div::repr() const
  {
    return "/ " + this->getChild(0)->repr()
          + " " + this->getChild(1)->repr();
  }
}
