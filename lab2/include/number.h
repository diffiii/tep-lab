#ifndef NUMBER_H
#define NUMBER_H

#include <string>
#include <vector>

static const unsigned char NUMBER_SYSTEM = 10;

typedef unsigned char digit;
typedef unsigned int uint;

class Number
{
public:
  Number();
  Number(int value);
  Number(const Number& other);

  Number& operator=(int value);
  Number& operator=(const Number& other);

  bool operator==(const Number& other) const;
  bool operator!=(const Number& other) const;
  bool operator<(const Number& other) const;
  bool operator>(const Number& other) const;
  bool operator<=(const Number& other) const;
  bool operator>=(const Number& other) const;

  void operator^=(int value);

  Number operator+(const Number& other) const;
  Number operator-(const Number& other) const;
  Number operator*(const Number& other) const;
  Number operator/(const Number& other) const;

  std::string toString() const;

private:
  uint length;
  digit* digits;
  bool isNegative;

  void initFromInt(int value, uint system);
  void initFromOther(const Number& other);

  int compareAbs(const Number& other) const;
  Number addAbs(const Number& other) const;
  Number subAbs(const Number& other) const;
  Number mulAbs(const Number& other) const;
  Number divAbs(const Number& other) const;
  void removeLeadingZeros();

  static std::vector<digit> uintToDigitsVector(uint number, uint system);
};

#endif
