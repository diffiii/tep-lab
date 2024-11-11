#include "nodes/numbers/variable.h"

namespace nodes
{
  Variable::Variable(const std::string &name, const Tree *tree)
  {
    this->name = name;
    this->tree= tree;
  }

  double Variable::eval() const
  {
    return this->tree->getVar(this->name);
  }

  std::string Variable::repr() const
  {
    return this->name;
  }
}
