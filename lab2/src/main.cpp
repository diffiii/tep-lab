#include <iostream>
#include <cstdlib>
#include <climits>
#include "number.h"

int main()
{
  std::cout << (Number(379) - Number(999)).toString() << "\n";
  std::cout << (Number(379) + Number(-999)).toString() << "\n";
  std::cout << (Number(1000) - Number(22)).toString() << "\n";
  std::cout << (Number(999) + Number(1)).toString() << "\n";
  std::cout << (Number(37) * Number(-11)).toString() << "\n";
  std::cout << (Number(-99) * Number(-2)).toString() << "\n";
  std::cout << (Number(121) * Number(3012)).toString() << "\n";
  std::cout << (Number(INT_MAX) * Number(INT_MAX)).toString() << "\n";
  std::cout << (Number(364452) / Number(13)).toString() << "\n";
  std::cout << (Number(3448182) / Number(-123)).toString() << "\n";
  std::cout << (Number(-89998) / Number(-7777)).toString() << "\n";

  Number test;
  test ^= 123;
  std::cout << test.toString() << "\n";

  return EXIT_SUCCESS;
}
