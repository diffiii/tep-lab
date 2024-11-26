#ifndef NUMBER_H
#define NUMBER_H

#include "node.h"

static const uint8_t NUMBER_CHILDREN_COUNT = 0;

namespace nodes
{
  class Number : public Node
  {
  public:
    uint8_t childrenCount() const override;
  };
}

#endif
