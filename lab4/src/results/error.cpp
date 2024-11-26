#include "results/error.h"

Error::Error()
{
  this->message = DEFAULT_ERROR_MESSAGE;
}

Error::Error(const std::string &message)
{
  this->message = message;
}

Error::Error(const Error &other)
{
  this->message = other.message;
}

std::string Error::toString() const
{
  return ERROR_MESSAGE_PREFIX + this->message;
}
