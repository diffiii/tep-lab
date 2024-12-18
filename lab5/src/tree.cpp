#include "tree.h"

#include <sstream>
#include "functions/cos.h"
#include "functions/sin.h"
#include "numbers/const.h"
#include "numbers/variable.h"
#include "operators/add.h"
#include "operators/div.h"
#include "operators/mul.h"
#include "operators/sub.h"

Tree::Tree()
{
  this->root = nullptr;
}

Tree::~Tree()
{
  delete this->root;
}

Result<Tree*, Error> Tree::enterFormula(const std::string &formula)
{
  std::istringstream stream(formula);
  std::vector<std::string> tokens;

  std::string current;
  while (stream >> current)
  {
    tokens.push_back(current);
  }

  const Result<nodes::Node*, Error> subtree = this->buildSubtree(tokens);

  if (subtree.isFailure())
  {
    return Result<Tree*, Error>::fail(subtree.getErrors());
  }

  this->root = subtree.getValue();

  if (!tokens.empty())
  {
    std::vector<Error*> errors;

    for (size_t i = 0; i < tokens.size(); i++)
    {
      errors.push_back(new Error(UNEXPECTED_TOKEN_ERROR_MESSAGE + tokens[i]));
    }

    return Result<Tree*, Error>::fail(errors);
  }

  return Result<Tree*, Error>::ok(this);
}

Result<uint8_t, Error> Tree::getVar(const std::string &name) const
{
  if (this->variables.count(name))
  {
    return Result<uint8_t, Error>::ok(this->variables.at(name));
  }

  return Result<uint8_t, Error>::fail(
    new Error(VARIABLE_NOT_FOUND_ERROR_MESSAGE)
  );
}

void Tree::setVars(const std::map<std::string, uint8_t> &vars)
{
  this->variables = vars;
}

Result<double, Error> Tree::eval() const
{
  if (this->root == nullptr)
  {
    return Result<double, Error>::fail(
      new Error(EMPTY_FORMULA_ERROR_MESSAGE)
    );
  }

  const Result<double, Error> result = this->root->eval();

  if (result.isFailure())
  {
    return Result<double, Error>::fail(result.getErrors());
  }

  return Result<double, Error>::ok(result.getValue());
}

std::string Tree::repr() const
{
  if (this->root == nullptr)
  {
    return "";
  }

  return this->root->repr();
}

bool Tree::empty() const
{
  return this->root == nullptr;
}

// Tree& Tree::operator=(const Tree &other)
// {
//   if (this != &other)
//   {
//     delete this->root;
//
//     // No need to check for errors here,
//     // because `other` must be ensured to be a valid tree.
//     this->enterFormula(other.repr());
//   }
//
//   return *this;
// }
//
// Tree Tree::operator+(const Tree &other) const
// {
//   Tree result;
//
//   const std::string &repr = this->repr();
//
//   if (!repr.empty())
//   {
//     result.enterFormula(repr.substr(0, repr.length() - 1) + other.repr());
//   }
//
//   return result;
// }

Result<std::string, Error> Tree::validateVarName(const std::string &name)
{
  bool containsLetter = false;
  std::string finalVarName;

  for (size_t i = 0; i < name.length(); i++)
  {
    const char current = name[i];

    if (isalpha(current))
    {
      containsLetter = true;
      finalVarName += current;
    }
    else if (isdigit(current))
    {
      finalVarName += current;
    }
    else
    {
      return Result<std::string, Error>::fail(
        new Error(UNEXPECTED_TOKEN_IN_VAR_ERROR_MESSAGE + name)
      );
    }
  }

  if (!containsLetter)
  {
    return Result<std::string, Error>::fail(
      new Error(VAR_NAME_CONTAINS_NO_LETTERS_ERROR_MESSAGE)
    );
  }

  return Result<std::string, Error>::ok(finalVarName);
}

Result<nodes::Node*, Error>
Tree::buildSubtree(std::vector<std::string> &tokens)
{
  if (tokens.empty())
  {
    return Result<nodes::Node*, Error>::fail(
      new Error(EMPTY_FORMULA_ERROR_MESSAGE)
    );
  }

  const std::string token = tokens.front();
  tokens.erase(tokens.begin());

  if ((token.length() == 1) && (isdigit(token[0])))
  {
    return Result<nodes::Node*, Error>::ok(
      new nodes::Const(static_cast<uint8_t>(token[0] - '0'))
    );
  }

  nodes::Node *newNode;

  if (token == ADD_OPERATOR_TOKEN)
  {
    newNode = new nodes::Add();
  }
  else if (token == SUB_OPERATOR_TOKEN)
  {
    newNode = new nodes::Sub();
  }
  else if (token == MUL_OPERATOR_TOKEN)
  {
    newNode = new nodes::Mul();
  }
  else if (token == DIV_OPERATOR_TOKEN)
  {
    newNode = new nodes::Div();
  }
  else if (token == SIN_FUNCTION_TOKEN)
  {
    newNode = new nodes::Sin();
  }
  else if (token == COS_FUNCTION_TOKEN)
  {
    newNode = new nodes::Cos();
  }
  else
  {
    const Result<std::string, Error> varName = this->validateVarName(token);

    if (varName.isFailure())
    {
      return Result<nodes::Node*, Error>::fail(varName.getErrors());
    }

    this->variableNames.insert(varName.getValue());

    return Result<nodes::Node*, Error>::ok(
      new nodes::Variable(varName.getValue(), this)
    );
  }

  for (uint8_t i = 0; i < newNode->childrenCount(); i++)
  {
    if (tokens.empty())
    {
      return Result<nodes::Node*, Error>::fail(
        new Error(NOT_ENOUGH_ARGUMENTS_ERROR_MESSAGE)
      );
    }

    Result<nodes::Node*, Error> child = this->buildSubtree(tokens);

    if (child.isFailure())
    {
      return Result<nodes::Node*, Error>::fail(child.getErrors());
    }

    newNode->setChild(i, child.getValue());
  }

  return Result<nodes::Node*, Error>::ok(newNode);
}

// New in list no. 5

Tree::Tree(Tree &&other) noexcept
{
  this->move(std::move(other));
}

Tree& Tree::operator=(Tree &&other) noexcept
{
  if (this != &other)
  {
    delete this->root;

    this->move(std::move(other));
  }

  return *this;
}

Tree Tree::operator=(const Tree &other)
{
  if (this != &other)
  {
    delete this->root;

    this->enterFormula(other.repr());
    this->variableNames = other.variableNames;
    this->variables = other.variables;
  }

  return std::move(*this);
}

Tree Tree::operator+(const Tree &other) const
{
  Tree result;

  const std::string &repr = this->repr();

  if (!repr.empty())
  {
    result.enterFormula(repr.substr(0, repr.length() - 1) + other.repr());
  }

  return std::move(result);
}

void Tree::move(Tree &&other)
{
  this->root = other.root;
  this->variableNames = other.variableNames;
  this->variables = other.variables;

  other.root = nullptr;
  other.variableNames.clear();
  other.variables.clear();
}
