#include <iostream>

#include "tree.h"

int main()
{
  Tree tree1;
  tree1.enterFormula("+ 1 2");

  Tree tree2;
  tree2.enterFormula("* 3 4");

  Tree result = tree1 + tree2;

  Tree other1 = std::move(tree1 + tree2);
  Tree other2 = std::move(result);

  std::cout << tree1.repr() << std::endl;
  std::cout << tree2.repr() << std::endl;
  std::cout << other1.repr() << std::endl;
  std::cout << other2.repr() << std::endl;

  return EXIT_SUCCESS;
}
