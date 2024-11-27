#ifndef RESULT_H
#define RESULT_H

#include <vector>

template <typename T, typename E>
class Result
{
public:
  Result(const T &value);
  Result(E *error);
  Result(std::vector<E*> &errors);
  Result(const Result &other);

  ~Result();

  static Result ok(const T &value);
  static Result fail(E *error);
  static Result fail(std::vector<E*> &errors);

  Result &operator=(const Result &other);

  bool isSuccess() const;
  bool isFailure() const;

  T getValue() const;
  std::vector<E*> &getErrors() const;

private:
  T *value;
  std::vector<E*> errors;
};

template <typename T, typename E>
Result<T, E>::Result(const T &value)
{
  this->value = new T(value);
}

template <typename T, typename E>
Result<T, E>::Result(E *error)
{
  this->value = nullptr;
  this->errors.push_back(error);
}

template <typename T, typename E>
Result<T, E>::Result(std::vector<E*> &errors)
{
  this->value = nullptr;

  for (size_t i = 0; i < errors.size(); i++)
  {
    this->errors.push_back(errors[i]);
  }
}

template <typename T, typename E>
Result<T, E>::Result(const Result &other)
{
  this->value = (other.value != nullptr) ? new T(*other.value) : nullptr;

  for (size_t i = 0; i < other.errors.size(); i++)
  {
    this->errors.push_back(new E(*other.errors[i]));
  }
}

template <typename T, typename E>
Result<T, E>::~Result()
{
  delete this->value;

  for (size_t i = 0; i < this->errors.size(); i++)
  {
    delete this->errors[i];
  }

  this->errors.clear();
}

template <typename T, typename E>
Result<T, E> Result<T, E>::ok(const T &value)
{
  return Result(value);
}

template <typename T, typename E>
Result<T, E> Result<T, E>::fail(E *error)
{
  return Result(error);
}

template <typename T, typename E>
Result<T, E> Result<T, E>::fail(std::vector<E*> &errors)
{
  return Result(errors);
}

template <typename T, typename E>
Result<T, E> &Result<T, E>::operator=(const Result &other)
{
  if (this != &other)
  {
    delete this->value;
    this->value = (other.value != nullptr) ? new T(*other.value) : nullptr;

    for (size_t i = 0; i < this->errors.size(); i++)
    {
      delete this->errors[i];
    }

    this->errors.clear();

    for (size_t i = 0; i < other.errors.size(); i++)
    {
      this->errors.push_back(new E(*other.errors[i]));
    }
  }

  return *this;
}

template <typename T, typename E>
bool Result<T, E>::isSuccess() const
{
  return this->errors.empty();
}

template <typename T, typename E>
bool Result<T, E>::isFailure() const
{
  return !this->errors.empty();
}

template <typename T, typename E>
T Result<T, E>::getValue() const
{
  // Returning a default-constructed value if the result is a failure
  return (this->isSuccess()) ? *this->value : T();
}

template <typename T, typename E>
std::vector<E*> &Result<T, E>::getErrors() const
{
  std::vector<E*> *errors = new std::vector<E*>();

  for (size_t i = 0; i < this->errors.size(); i++)
  {
    errors->push_back(new E(*this->errors[i]));
  }

  return *errors;
}

#include "result_void.h"

#endif
