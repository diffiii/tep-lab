#include "functions/function.h"

namespace nodes
{
  Function::Function()
  {
    this->children = new Node*[1];
  }

  Function::~Function()
  {
    delete[] this->children;
  }

  uint8_t Function::childrenCount() const
  {
    return FUNCTION_CHILDREN_COUNT;
  }
}
