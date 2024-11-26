#ifndef OPERATOR_H
#define OPERATOR_H

#include "node.h"

static const uint8_t OPERATOR_CHILDREN_COUNT = 2;

namespace nodes
{
  class Operator : public Node
  {
  public:
    Operator();
    ~Operator() override;
    uint8_t childrenCount() const override;
  };
}

#endif
