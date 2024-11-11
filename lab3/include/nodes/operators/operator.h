#ifndef OPERATOR_H
#define OPERATOR_H

#include "nodes/base.h"

namespace nodes
{
  class Operator : public Base
  {
  public:
    Operator();
    ~Operator() override;
    Base* getChild(uint8_t index) const override;
    bool setChild(uint8_t index, const Base *node) override;
    uint8_t childrenCount() const override;
  };
}

#endif
