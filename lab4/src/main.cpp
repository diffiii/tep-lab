#include <iostream>

#include "tree.h"
#include "saver.h"
#include "result.h"

int main()
{
  const std::string formula = "* 2 sin + x - 1 / a 3 c d";

  Tree *tree = new Tree();
  Saver<Tree*> *saver = new Saver<Tree*>();

  const Result<Tree*, Error> enterResult = tree->enterFormula(formula);
  const std::vector<Error*> enterErrors = enterResult.getErrors();

  for (size_t i = 0; i < enterErrors.size(); i++)
  {
    std::cout << *enterErrors[i] << std::endl;
  }

  const Result<void, Error> openResult = saver->open("file.txt");
  const std::vector<Error*> openErrors = openResult.getErrors();

  for (size_t i = 0; i < openErrors.size(); i++)
  {
    std::cout << *openErrors[i] << std::endl;
  }

  const Result<void, Error> saveResult = saver->save(enterResult);
  const std::vector<Error*> saveErrors = saveResult.getErrors();

  for (size_t i = 0; i < saveErrors.size(); i++)
  {
    std::cout << *saveErrors[i] << std::endl;
  }

  delete saver;
  delete tree;
}
