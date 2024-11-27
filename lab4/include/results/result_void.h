#ifndef RESULTVOID_H
#define RESULTVOID_H

template <typename E>
class Result<void, E>
{
public:
  Result() = default;
  Result(E *error);
  Result(std::vector<E*> &errors);
  Result(const Result &other);

  ~Result();

  static Result ok();
  static Result fail(E *error);
  static Result fail(std::vector<E*> &errors);

  Result &operator=(const Result &other);

  bool isSuccess() const;
  bool isFailure() const;

  const std::vector<E*> &getErrors() const;

private:
  std::vector<E*> errors;
};

template <typename E>
Result<void, E>::Result(E* error)
{
  this->errors.push_back(error);
}

template <typename E>
Result<void, E>::Result(std::vector<E*> &errors)
{
  for (size_t i = 0; i < errors.size(); i++)
  {
    this->errors.push_back(errors[i]);
  }
}

template <typename E>
Result<void, E>::Result(const Result &other)
{
  for (size_t i = 0; i < other.errors.size(); i++)
  {
    this->errors.push_back(new E(*other.errors[i]));
  }
}

template <typename E>
Result<void, E>::~Result()
{
  for (size_t i = 0; i < this->errors.size(); i++)
  {
    delete this->errors[i];
  }

  this->errors.clear();
}

template <typename E>
Result<void, E> Result<void, E>::ok()
{
  return Result();
}

template <typename E>
Result<void, E> Result<void, E>::fail(E *error)
{
  return Result(error);
}

template <typename E>
Result<void, E> Result<void, E>::fail(std::vector<E*> &errors)
{
  return Result(errors);
}

template <typename E>
Result<void, E> &Result<void, E>::operator=(const Result &other)
{
  if (this != &other)
  {
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

template <typename E>
bool Result<void, E>::isSuccess() const
{
  return this->errors.empty();
}

template <typename E>
bool Result<void, E>::isFailure() const
{
  return !this->errors.empty();
}

template <typename E>
const std::vector<E*> &Result<void, E>::getErrors() const
{
  std::vector<E*> *errors = new std::vector<E*>();

  for (size_t i = 0; i < this->errors.size(); i++)
  {
    errors->push_back(new E(*this->errors[i]));
  }

  return *errors;
}

#endif
