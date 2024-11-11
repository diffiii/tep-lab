#ifndef NUMBER_H
#define NUMBER_H

#include "nodes/base.h"

namespace nodes
{
  class Number : public Base
  {
  public:
    Base* getChild( uint8_t index ) const override;
    bool setChild( uint8_t index, const Base* node ) override;
    uint8_t childrenCount() const override;
  };
}

#endif
