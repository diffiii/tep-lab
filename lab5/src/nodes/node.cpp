#include "node.h"

namespace nodes
{
  Node::Node()
  {
    this->children = nullptr;
  }

  Node* Node::getChild(const uint8_t index) const
  {
    if (index >= this->childrenCount())
    {
      return nullptr;
    }

    return this->children[index];
  }

  bool Node::setChild(const uint8_t index, const Node *node)
  {
    if (index >= this->childrenCount())
    {
      return false;
    }

    this->children[index] = const_cast<Node*>(node);
    return true;
  }
}
