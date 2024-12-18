#include "refcount.h"

RefCounter::RefCounter(const usize count)
{
  this->count = count;
}

usize RefCounter::get() const
{
  return this->count;
}

usize RefCounter::increment()
{
  return ++this->count;
}

usize RefCounter::decrement()
{
  return --this->count;
}
