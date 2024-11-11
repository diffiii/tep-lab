#include "tree.h"

#include <iostream>
#include <sstream>
#include "cli.h"
#include "nodes/functions/sin.h"
#include "nodes/functions/cos.h"
#include "nodes/numbers/const.h"
#include "nodes/numbers/variable.h"
#include "nodes/operators/add.h"
#include "nodes/operators/sub.h"
#include "nodes/operators/mul.h"
#include "nodes/operators/div.h"

Tree::Tree()
{
  this->root = nullptr;
}

Tree::~Tree()
{
  delete this->root;
}

void Tree::enterFormula(const std::string &formula)
{
  this->varNames.clear();
  this->vars.clear();

  std::istringstream stream(formula);
  std::vector<std::string> tokens;

  std::string current;
  while (stream >> current)
  {
    tokens.push_back(current);
  }

  this->root = this->buildSubtree(tokens);

  if (!tokens.empty())
  {
    for (const std::string &token : tokens)
    {
      std::cout << SKIPPING_TOKEN << token << "\n";
    }
  }
}

void Tree::setVars(const std::map<std::string, uint8_t> &vars)
{
  this->vars = vars;
}

uint8_t Tree::getVar(const std::string &name) const
{
  if (this->vars.count(name))
  {
    return this->vars.at(name);
  }

  std::cout << VAR_VALUE_NOT_FOUND;
  return 0;
}

std::set<std::string> Tree::getVars() const
{
  return this->varNames;
}

double Tree::eval() const
{
  return this->root->eval();
}

std::string Tree::repr() const
{
  return this->root->repr();
}

bool Tree::empty() const
{
  return this->root == nullptr;
}

std::string Tree::validateVarName(const std::string &name)
{
  bool containsLetter = false;
  std::string finalVarName;

  for (size_t i = 0; i < name.length(); i++)
  {
    const char current = name[i];

    if ((current >= 'a' && current <= 'z')
     || (current >= 'A' && current <= 'Z'))
    {
      containsLetter = true;
      finalVarName += current;
    }
    else if (current >= '0' && current <= '9')
    {
      finalVarName += current;
    }
    else
    {
      std::cout << INVALID_CHAR << current << "\n";
    }
  }

  if (!containsLetter)
  {
    std::cout << VAR_NO_LETTER;
    return DEFAULT_VAR_NAME;
  }

  return finalVarName;
}

nodes::Base *Tree::buildSubtree(std::vector<std::string> &tokens)
{
  if (tokens.empty())
  {
    return nullptr;
  }

  const std::string current = tokens[0];
  tokens.erase(tokens.begin());

  if (current.length() == 1 && isdigit(current[0]))
  {
    return new nodes::Const(static_cast<char>(current[0] - '0'));
  }

  nodes::Base *node;

  if (current == "+")
  {
    node = new nodes::Add();
  }
  else if (current == "-")
  {
    node = new nodes::Sub();
  }
  else if (current == "*")
  {
    node = new nodes::Mul();
  }
  else if (current == "/")
  {
    node = new nodes::Div();
  }
  else if (current == "sin")
  {
    node = new nodes::Sin();
  }
  else if (current == "cos")
  {
    node = new nodes::Cos();
  }
  else
  {
    const std::string validatedVarName = validateVarName(current);
    this->varNames.insert(validatedVarName);
    return new nodes::Variable(validatedVarName, this);
  }

  for (uint8_t i = 0; i < node->childrenCount(); i++)
  {
    if (tokens.empty())
    {
      std::cout << NOT_ENOUGH_ARGS;
      node->setChild(i, new nodes::Const());
    }
    else
    {
      node->setChild(i, this->buildSubtree(tokens));
    }
  }

  return node;
}
