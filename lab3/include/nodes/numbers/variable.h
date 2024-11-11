#ifndef VARIABLE_H
#define VARIABLE_H

#include "nodes/numbers/number.h"
#include "tree.h"

namespace nodes
{
  class Variable final : public Number
  {
  public:
    explicit Variable(const std::string &name, const Tree *tree);
    double eval() const override;
    std::string repr() const override;

  private:
    std::string name;
    const Tree *tree;
  };
}

#endif
