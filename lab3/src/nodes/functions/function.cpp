#include "nodes/functions/function.h"

namespace nodes
{
  Function::Function()
  {
    this->children = new Base*[1];
  }

  Function::~Function()
  {
    delete[] this->children;
  }

  Base* Function::getChild( const uint8_t index ) const
  {
    return this->children[0];
  }

  bool Function::setChild(const uint8_t index, const Base *node)
  {
    if (index != 0)
    {
      return false;
    }

    this->children[0] = const_cast<Base*>(node);
    return true;
  }

  uint8_t Function::childrenCount() const
  {
    return 1;
  }
}
