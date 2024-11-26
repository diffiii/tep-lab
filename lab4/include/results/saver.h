#ifndef SAVER_H
#define SAVER_H

#include <fstream>
#include "error.h"
#include "result.h"
#include "tree.h"

static const std::string FAILED_TO_OPEN_FILE_ERROR_MESSAGE =
  "Failed to open file: ";

static const std::string FILE_IS_NOT_OPEN_ERROR_MESSAGE =
  "File is not open";

template <typename T>
class Saver
{
public:
  ~Saver();
  Result<void, Error> open(const std::string &filename);
  Result<void, Error> save(const Result<T, Error> &data);

private:
  std::ofstream file;
};

template <typename T>
Saver<T>::~Saver()
{
  if (this->file.is_open())
  {
    this->file.close();
  }
}

template <typename T>
Result<void, Error> Saver<T>::open(const std::string &filename)
{
  this->file.open(
    filename,
    std::ios::out
  );

  if (!this->file.is_open())
  {
    return Result<void, Error>::fail(
      new Error(FAILED_TO_OPEN_FILE_ERROR_MESSAGE + filename)
    );
  }

  this->file.clear();

  return Result<void, Error>::ok();
}

template <typename T>
Result<void, Error> Saver<T>::save(const Result<T, Error> &data)
{
  if (!this->file.is_open())
  {
    return Result<void, Error>::fail(
      new Error(FILE_IS_NOT_OPEN_ERROR_MESSAGE)
    );
  }

  if (data.isFailure())
  {
    const std::vector<Error*> errors = data.getErrors();

    for (size_t i = 0; i < errors.size(); i++)
    {
      this->file << errors[i]->toString() << "\n";
    }
  }

  return Result<void, Error>::ok();
}

template<>
inline Result<void, Error> Saver<Tree*>::save(const Result<Tree*, Error> &data)
{
  if (!this->file.is_open())
  {
    return Result<void, Error>::fail(
      new Error(FILE_IS_NOT_OPEN_ERROR_MESSAGE)
    );
  }

  if (data.isSuccess())
  {
    const Tree *tree = data.getValue();
    this->file << tree->repr() << "\n";
  }
  else
  {
    const std::vector<Error*> &errors = data.getErrors();

    for (size_t i = 0; i < errors.size(); i++)
    {
      this->file << errors[i]->toString() << "\n";
    }
  }

  return Result<void, Error>::ok();
}

#endif
