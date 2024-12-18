#include "numbers/variable.h"

namespace nodes
{
  Variable::Variable(const std::string &name, const Tree *tree)
  {
    this->name = name;
    this->tree = tree;
  }

  Result<double, Error> Variable::eval() const
  {
    const Result<uint8_t, Error> value = this->tree->getVar(this->name);

    if (value.isFailure())
    {
      return Result<double, Error>::fail(value.getErrors());
    }

    return Result<double, Error>::ok(value.getValue());
  }

  std::string Variable::repr() const
  {
    return this->name;
  }
}
