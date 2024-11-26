#ifndef TREE_H
#define TREE_H

#include <string>
#include <set>
#include <map>
#include "nodes/node.h"
#include "result.h"
#include "error.h"

static const std::string ADD_OPERATOR_TOKEN = "+";
static const std::string SUB_OPERATOR_TOKEN = "-";
static const std::string MUL_OPERATOR_TOKEN = "*";
static const std::string DIV_OPERATOR_TOKEN = "/";
static const std::string SIN_FUNCTION_TOKEN = "sin";
static const std::string COS_FUNCTION_TOKEN = "cos";

static const std::string EMPTY_FORMULA_ERROR_MESSAGE =
  "Empty formula";

static const std::string NOT_ENOUGH_ARGUMENTS_ERROR_MESSAGE =
  "Not enough arguments";

static const std::string VARIABLE_NOT_FOUND_ERROR_MESSAGE =
  "Variable not found";

static const std::string UNEXPECTED_TOKEN_ERROR_MESSAGE =
  "Found unexpected token: ";

static const std::string UNEXPECTED_TOKEN_IN_VAR_ERROR_MESSAGE =
  "Unexpected token in variable: ";

static const std::string VAR_NAME_CONTAINS_NO_LETTERS_ERROR_MESSAGE =
  "Variable name contains no letters";

class Tree
{
public:
  Tree();
  ~Tree();
  Result<Tree*, Error> enterFormula(const std::string &formula);
  Result<uint8_t, Error> getVar(const std::string &name) const;
  void setVars(const std::map<std::string, uint8_t> &vars);
  Result<double, Error> eval() const;
  std::string repr() const;
  bool empty() const;
  Tree& operator=(const Tree &other);
  Tree operator+(const Tree &other) const;

private:
  nodes::Node *root;
  std::set<std::string> variableNames;
  std::map<std::string, uint8_t> variables;

  static Result<std::string, Error> validateVarName(const std::string &name);
  Result<nodes::Node*, Error> buildSubtree(std::vector<std::string> &tokens);
};

#endif
