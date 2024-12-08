#ifndef TREE_H
#define TREE_H

#include <map>
#include <set>
#include <vector>
#include <string>
#include "nodes/base.h"

static const std::string DEFAULT_VAR_NAME = "default";

static const std::string PLUS_SIGN = "+";
static const std::string MINUS_SIGN = "-";
static const std::string MULT_SIGN = "*";
static const std::string DIV_SIGN = "/";
static const std::string SIN_SIGN = "sin";
static const std::string COS_SIGN = "cos";

class Tree
{
public:
  Tree();
  ~Tree();
  void enterFormula(const std::string &formula);
  void setVars(const std::map<std::string, uint8_t> &vars);
  uint8_t getVar(const std::string &name) const;
  std::set<std::string> getVars() const;
  double eval() const;
  std::string repr() const;
  bool empty() const;
  Tree& operator=(const Tree &other);
  Tree operator+(const Tree &other) const;

  uint leavesCount() const;

private:
  nodes::Base *root;
  std::set<std::string> varNames;
  std::map<std::string, uint8_t> vars;

  static std::string validateVarName(const std::string &name);
  nodes::Base* buildSubtree(std::vector<std::string> &tokens);
};

#endif
