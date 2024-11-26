#ifndef VARIABLE_H
#define VARIABLE_H

#include "tree.h"
#include "numbers/number.h"

namespace nodes
{
  class Variable final : public Number
  {
  public:
    Variable(const std::string &name, const Tree *tree);
    Result<double, Error> eval() const override;
    std::string repr() const override;

  private:
    std::string name;
    const Tree *tree;
  };
}

#endif
