#ifndef FUNCTION_H
#define FUNCTION_H

#include "node.h"

static const uint8_t FUNCTION_CHILDREN_COUNT = 1;

namespace nodes
{
  class Function : public Node
  {
  public:
    Function();
    ~Function() override;
    uint8_t childrenCount() const override;
  };
}

#endif
