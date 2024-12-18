#ifndef REFCOUNT_H
#define REFCOUNT_H

typedef unsigned long long usize;

class RefCounter
{
public:
  explicit RefCounter(usize count = 0);

  usize get() const;
  usize increment();
  usize decrement();

private:
  usize count;
};

#endif
