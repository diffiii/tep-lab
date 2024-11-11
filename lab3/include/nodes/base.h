#ifndef BASE_H
#define BASE_H

#include "cstdint"
#include "string"

namespace nodes
{
  class Base
  {
  public:
    Base();
    virtual ~Base() = default;
    virtual Base* getChild(uint8_t index) const = 0;
    virtual bool setChild(uint8_t index, const Base *node) = 0;
    virtual double eval() const = 0;
    virtual std::string repr() const = 0;
    virtual uint8_t childrenCount() const = 0;

  protected:
    Base **children;
  };
}

#endif
