#ifndef NODE_H
#define NODE_H

#include <cstdint>
#include <string>
#include "result.h"
#include "error.h"

static const std::string INDEX_OUT_OF_BOUNDS_ERROR_MESSAGE =
  "Index out of bounds";

namespace nodes
{
  class Node
  {
  public:
    Node();
    virtual ~Node() = default;
    Node* getChild(uint8_t index) const;
    bool setChild(uint8_t index, const Node *node);
    virtual Result<double, Error> eval() const = 0;
    virtual std::string repr() const = 0;
    virtual uint8_t childrenCount() const = 0;

  protected:
    Node **children;
  };
}

#endif
