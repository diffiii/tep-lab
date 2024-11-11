#include "nodes/operators/operator.h"

namespace nodes
{
  Operator::Operator()
  {
    this->children = new Base*[2];
  }

  Operator::~Operator()
  {
    delete[] this->children;
  }

  Base* Operator::getChild(const uint8_t index) const
  {
    if (index < 0 || index > 1)
    {
      return nullptr;
    }

    return this->children[index];
  }

  bool Operator::setChild(const uint8_t index, const Base *node)
  {
    if (index < 0 || index > 1)
    {
      return false;
    }

    this->children[index] = const_cast<Base*>(node);
    return true;
  }

  uint8_t Operator::childrenCount() const
  {
    return 2;
  }
}
