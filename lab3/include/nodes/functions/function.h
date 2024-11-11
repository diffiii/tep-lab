#ifndef FUNCTION_H
#define FUNCTION_H

#include "nodes/base.h"

namespace nodes
{
  class Function : public Base
  {
  public:
    Function();
    ~Function() override;
    Base* getChild(uint8_t index) const override;
    bool setChild(uint8_t index, const Base *node) override;
    uint8_t childrenCount() const override;
  };
}

#endif
