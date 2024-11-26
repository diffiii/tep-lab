#include "operators/operator.h"

namespace nodes
{
  Operator::Operator()
  {
    this->children = new Node*[2];
  }

  Operator::~Operator()
  {
    delete[] this->children;
  }

  uint8_t Operator::childrenCount() const
  {
    return OPERATOR_CHILDREN_COUNT;
  }
}
