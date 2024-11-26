#ifndef ERROR_H
#define ERROR_H

#include <string>

static const std::string DEFAULT_ERROR_MESSAGE =
  "An unknown error occurred";

static const std::string ERROR_MESSAGE_PREFIX =
  "[ERROR] ";

class Error
{
public:
  Error();
  Error(const std::string &message);
  Error(const Error &other);
  ~Error() = default;
  std::string toString() const;

private:
  std::string message;
};

#endif
