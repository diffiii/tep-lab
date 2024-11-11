#include "nodes/numbers/number.h"

namespace nodes
{
  Base *Number::getChild(const uint8_t index) const
  {
    return nullptr;
  }

  bool Number::setChild(const uint8_t index, const Base *node)
  {
    return false;
  }

  uint8_t Number::childrenCount() const
  {
    return 0;
  }
}
