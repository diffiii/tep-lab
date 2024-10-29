#include "number.h"

#include <algorithm>
#include <iostream>

Number::Number()
{
  this->length = 0;
  this->digits = NULL;
  this->isNegative = false;
}

Number::Number(const int value)
{
  this->initFromInt(value);
}

Number::Number(const Number& other)
{
  this->initFromOther(other);
}

Number& Number::operator=(const int value)
{
  delete[] this->digits;
  this->initFromInt(value);

  return *this;
}

Number& Number::operator=(const Number& other)
{
  if (this != &other)
  {
    delete[] this->digits;
    this->initFromOther(other);
  }

  return *this;
}

bool Number::operator==(const Number& other) const
{
  return (this->isNegative == other.isNegative)
    && (this->compareAbs(other) == 0);
}

bool Number::operator!=(const Number& other) const
{
  return !(*this == other);
}

bool Number::operator<(const Number& other) const
{
  return (this->isNegative && !other.isNegative)
    || ((this->compareAbs(other) < 0)
        && (this->isNegative == other.isNegative));
}

bool Number::operator>(const Number& other) const
{
  return ((*this != other) && (*this >= other));
}

bool Number::operator<=(const Number& other) const
{
  return !(*this > other);
}

bool Number::operator>=(const Number& other) const
{
  return !(*this < other);
}

Number Number::operator+(const Number& other) const
{
  Number result;

  if (this->isNegative == other.isNegative)
  {
    result = this->addAbs(other);
    result.isNegative = this->isNegative;
  }
  else
  {
    const int cmp = this->compareAbs(other);

    if (cmp == 0)
    {
      result = Number(0);
    }
    else if (cmp > 0)
    {
      result = this->subAbs(other);
      result.isNegative = this->isNegative;
    }
    else
    {
      result = other.subAbs(*this);
      result.isNegative = other.isNegative;
    }
  }

  return result;
}

Number Number::operator-(const Number& other) const
{
  Number result;

  if (this->isNegative != other.isNegative)
  {
    result = this->addAbs(other);
    result.isNegative = this->isNegative;
  }
  else
  {
    const int cmp = this->compareAbs(other);

    if (cmp == 0)
    {
      result = Number(0);
    }
    else if (cmp > 0)
    {
      result = this->subAbs(other);
      result.isNegative = this->isNegative;
    }
    else
    {
      result = other.subAbs(*this);
      result.isNegative = !this->isNegative;
    }
  }

  return result;
}

Number Number::operator*(const Number& other) const
{
  Number result;

  if ((this->length == 0) || (other.length == 0))
  {
    result = Number(0);
    return result;
  }

  result = this->mulAbs(other);

  result.isNegative = (this->isNegative != other.isNegative);

  return result;
}

Number Number::operator/(const Number& other) const
{
  if (other.length == 0)
  {
    std::cout << "ERROR: Division by zero\n";
  }

  if (this->length == 0 || other.length == 0)
  {
    return Number();
  }

  Number result = this->divAbs(other);

  result.isNegative = (this->isNegative != other.isNegative);

  return result;
}

std::string Number::toString() const
{
  if (this->length == 0)
  {
    return "0";
  }

  std::string result = this->isNegative ? "-" : "";

  for (int i = 0; i < this->length; i++)
  {
    result += this->digits[i] + '0';
  }

  return result;
}

void Number::initFromInt(int value)
{
  if (value < 0)
  {
    this->isNegative = true;
    value = -value;
  }
  else
  {
    this->isNegative = false;
  }

  const std::vector<digit> valueAsString = uintToDigitsVector(value);

  this->length = valueAsString.size();
  this->digits = new digit[this->length];

  for (int i = 0; i < this->length; i++)
  {
    this->digits[i] = valueAsString.at(i);
  }
}

void Number::initFromOther(const Number &other)
{
  this->length = other.length;
  this->digits = new digit[this->length];
  this->isNegative = other.isNegative;

  std::copy(other.digits, other.digits + this->length, this->digits);
}

int Number::compareAbs(const Number& other) const
{
  if (this->length != other.length)
  {
    return (this->length > other.length) ? 1 : -1;
  }

  for (int i = 0; i < this->length; i++)
  {
    if (this->digits[i] != other.digits[i])
    {
      return (this->digits[i] > other.digits[i]) ? 1 : -1;
    }
  }

  return 0;
}

Number Number::addAbs(const Number &other) const
{
  const int maxLength = std::max(this->length, other.length);

  Number result;
  result.length = maxLength + 1;
  result.digits = new digit[result.length];

  int carry = 0;
  int iter = this->length - 1;
  int otherIter = other.length - 1;
  int resultIter = result.length - 1;

  for (int i = 0; i < this->length; i++)
  {
    result.digits[i] = 0;
  }

  while (iter >= 0 || otherIter >= 0 || carry != 0)
  {
    int sum = carry;

    if (iter >= 0)
    {
      sum += this->digits[iter--];
    }

    if (otherIter >= 0)
    {
      sum += other.digits[otherIter--];
    }

    result.digits[resultIter--] = sum % NUMBER_SYSTEM;
    carry = sum / NUMBER_SYSTEM;
  }

  result.removeLeadingZeros();

  if (result.length == 0)
  {
    delete[] result.digits;
  }

  return result;
}

Number Number::subAbs(const Number &other) const
{
  Number result;
  result.length = this->length;
  result.digits = new digit[result.length];

  int borrow = 0;
  int iter = this->length - 1;
  int otherIter = other.length - 1;
  int resultIter = result.length - 1;

  for (int i = 0; i < result.length; i++)
  {
    result.digits[i] = 0;
  }

  while (iter >= 0)
  {
    int diff = this->digits[iter] - borrow;

    if (otherIter >= 0)
    {
      diff -= other.digits[otherIter];
      otherIter--;
    }

    if (diff < 0)
    {
      diff += NUMBER_SYSTEM;
      borrow = 1;
    }
    else
    {
      borrow = 0;
    }

    result.digits[resultIter] = diff;

    iter--;
    resultIter--;
  }

  result.removeLeadingZeros();

  if (result.length == 0)
  {
    delete[] result.digits;
  }

  return result;
}

Number Number::mulAbs(const Number& other) const
{
  const int resultLength = this->length + other.length;

  Number result;
  result.length = resultLength;
  result.digits = new digit[result.length];

  for (int i = 0; i < result.length; i++)
  {
    result.digits[i] = 0;
  }

  for (int i = this->length - 1; i >= 0; i--)
  {
    int carry = 0;

    for (int j = other.length - 1; j >= 0; j--)
    {
      const int sum = this->digits[i] * other.digits[j]
                    + result.digits[i + j + 1] + carry;

      carry = sum / NUMBER_SYSTEM;
      result.digits[i + j + 1] = sum % NUMBER_SYSTEM;
    }

    result.digits[i] += carry;
  }

  result.removeLeadingZeros();

  if (result.length == 0)
  {
    delete[] result.digits;
  }

  return result;
}

Number Number::divAbs(const Number& other) const
{
  Number remainder;

  Number result;
  result.length = this->length;
  result.digits = new digit[result.length];

  Number divisor = other;
  divisor.isNegative = false;

  uint qIdx = 0;

  for (uint idx = 0; idx < this->length; idx++)
  {
    const uint newLength = remainder.length + 1;
    digit* newDigits = new digit[newLength];

    for (uint i = 0; i < remainder.length; i++)
    {
      newDigits[i] = remainder.digits[i];
    }

    newDigits[newLength - 1] = this->digits[idx];

    delete[] remainder.digits;

    remainder.length = newLength;
    remainder.digits = newDigits;

    uint leadingZeros = 0;

    while ((leadingZeros < remainder.length - 1)
        && (remainder.digits[leadingZeros] == 0))
    {
      leadingZeros++;
    }

    if (leadingZeros > 0)
    {
      for (uint i = 0; i < remainder.length - leadingZeros; i++)
      {
        remainder.digits[i] = remainder.digits[i + leadingZeros];
      }

      remainder.length -= leadingZeros;
    }

    digit quotientDigit = 0;

    while (remainder.compareAbs(divisor) >= 0)
    {
      const Number tempRemainder = remainder.subAbs(divisor);
      remainder = tempRemainder;
      quotientDigit++;
    }

    result.digits[qIdx++] = quotientDigit;
  }

  result.length = qIdx;

  result.removeLeadingZeros();

  delete[] remainder.digits;

  if (result.length == 0)
  {
    delete[] result.digits;
  }

  return result;
}

void Number::removeLeadingZeros()
{
  uint leadingZerosResult = 0;

  while ((leadingZerosResult < this->length - 1)
      && (this->digits[leadingZerosResult] == 0))
  {
    leadingZerosResult++;
  }

  if (leadingZerosResult > 0)
  {
    for (uint i = 0; i < this->length - leadingZerosResult; i++)
    {
      this->digits[i] = this->digits[i + leadingZerosResult];
    }

    this->length -= leadingZerosResult;
  }
}

std::vector<digit> Number::uintToDigitsVector(uint number)
{
  std::vector<digit> result;

  while (number)
  {
    result.push_back(number % NUMBER_SYSTEM);
    number /= NUMBER_SYSTEM;
  }

  std::reverse(result.begin(), result.end());

  return result;
}
