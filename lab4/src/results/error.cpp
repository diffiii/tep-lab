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

Error::operator std::string() const
{
  return ERROR_MESSAGE_PREFIX + this->message;
}

std::ostream& operator<<(std::ostream &os, const Error &error)
{
  return (os << std::string(error));
}
