#ifndef RESULT_SAME_H
#define RESULT_SAME_H

template <typename TE>
class Result<TE*, TE>
{
public:
  Result();
  Result(const Result &other);

  ~Result();

  static Result ok(TE *value);
  static Result fail(TE *error);
  static Result fail(std::vector<TE*> &errors);

  Result &operator=(const Result &other);

  bool isSuccess() const;

  TE* getValue() const;
  std::vector<TE*>& getErrors() const;

private:
  TE *value;
  std::vector<TE*> errors;
};

template <typename TE>
Result<TE*, TE>::Result()
{
  this->value = nullptr;
}

template <typename TE>
Result<TE*, TE>::Result(const Result &other)
{
  this->value = new TE(*other.value);

  std::vector<TE*> errors;

  for (size_t i = 0; i < other.errors.size(); i++)
  {
    errors[i] = new TE(*other.errors[i]);
  }
}

template <typename TE>
Result<TE*, TE>::~Result()
{
  delete this->value;

  for (size_t i = 0; i < this->errors.size(); i++)
  {
    delete this->errors[i];
  }

  this->errors.clear();
}

template <typename TE>
Result<TE*, TE> Result<TE*, TE>::ok(TE *value)
{
  Result result;
  result.value = new TE(*value);

  return result;
}

template <typename TE>
Result<TE*, TE> Result<TE*, TE>::fail(TE *error)
{
  Result result;
  result.errors.push_back(new TE(*error));

  return result;
}

template<typename TE>
Result<TE*, TE> Result<TE*, TE>::fail(std::vector<TE *> &errors)
{
  Result result;

  for (size_t i = 0; i < errors.size(); i++)
  {
    result.errors->push_back(new TE(*errors[i]));
  }

  return result;
}

template <typename TE>
Result<TE*, TE>& Result<TE*, TE>::operator=(const Result &other)
{
  if (this != &other)
  {
    delete this->value;

    for (size_t i = 0; i < this->errors.size(); i++)
    {
      delete this->errors[i];
    }

    this->errors.clear();

    this->value = new TE(*other.value);

    for (size_t i = 0; i < other.errors.size(); i++)
    {
      this->errors->push_back(new TE(*other.errors[i]));
    }
  }

  return *this;
}

template<typename TE>
bool Result<TE*, TE>::isSuccess() const
{
  return this->value != nullptr && this->errors.empty();
}


template <typename TE>
TE* Result<TE*, TE>::getValue() const
{
  return (this->isSuccess()) ? this->value : new TE();
}

template <typename TE>
std::vector<TE*>& Result<TE*, TE>::getErrors() const
{
  std::vector<TE*> *errors = new std::vector<TE*>();

  for (size_t i = 0; i < this->errors.size(); i++)
  {
    errors->push_back(new TE(*this->errors[i]));
  }

  return *errors;
}

#endif
