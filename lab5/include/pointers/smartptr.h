#ifndef SMARTPTR_H
#define SMARTPTR_H

#include "refcount.h"

template <typename T>
class SmartPtr
{
public:
  SmartPtr(T *pointer = nullptr);
  SmartPtr(const SmartPtr &other);
  ~SmartPtr();

  SmartPtr& operator=(const SmartPtr &other);

  T& operator*();
  T* operator->();

private:
  T *pointer;
  RefCounter *counter;

  void clear();
  void copy(const SmartPtr &other);
};

template <typename T>
SmartPtr<T>::SmartPtr(T *pointer)
{
  this->pointer = pointer;
  this->counter = (pointer != nullptr) ? new RefCounter(1) : nullptr;
}

template <typename T>
SmartPtr<T>::SmartPtr(const SmartPtr &other)
{
  this->copy(other);
}

template <typename T>
SmartPtr<T>::~SmartPtr()
{
  this->clear();
}

template <typename T>
SmartPtr<T>& SmartPtr<T>::operator=(const SmartPtr &other)
{
  if (this != &other)
  {
    this->clear();
    this->copy(other);
  }

  return *this;
}

template <typename T>
T& SmartPtr<T>::operator*()
{
  return *this->pointer;
}

template <typename T>
T* SmartPtr<T>::operator->()
{
  return this->pointer;
}

template <typename T>
void SmartPtr<T>::clear()
{
  if ((this->counter != nullptr) && (this->counter->decrement() == 0))
  {
    delete this->pointer;
    delete this->counter;
  }
}

template <typename T>
void SmartPtr<T>::copy(const SmartPtr &other)
{
  this->pointer = other.pointer;
  this->counter = other.counter;
  this->counter->increment();
}

#endif
