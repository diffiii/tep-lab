#ifndef CLI_H
#define CLI_H

#include <string>
#include "tree.h"

static const std::string LINE_PREFIX = "> ";

static const std::string BANNER =
  " __  __      _   _  _____             ___ _    ___\n"
  "|  \\/  |__ _| |_| ||_   _| _ ___ ___ / __| |  |_ _|\n"
  "| |\\/| / _` |  _| ' \\| || '_/ -_) -_) (__| |__ | |\n"
  "|_|  |_\\__,_|\\__|_||_|_||_| \\___\\___|\\___|____|___|\n"
  "\n"
  "Type `" + LINE_PREFIX + "help` for usage information.\n"
  "\n";

static const std::string HELP =
  "These are all MathTreeCLi's available commands:\n"
  ""
  "  help                             "
  "Display this information screen\n"
  ""
  "  enter <formula>                  "
  "Try to create a tree based on the formula written in prefix notation\n"
  ""
  "  vars                             "
  "Display all variables' names used in the tree\n"
  ""
  "  print                            "
  "Display currently saved tree in prefix notation\n"
  ""
  "  leaves                           "
  "Display the number of leaves in the tree\n"
  ""
  "  comp <var1> <var2> ... <varN>    "
  "Evaluate tree's value based on given variables' values\n"
  ""
  "  join <formula>                   "
  "Try to create a tree based on the formula and join it to the saved tree\n"
  ""
  "  exit                             "
  "Terminate MathTreeCLI's execution\n";

static const std::string HELP_COMMAND = "help";
static const std::string ENTER_COMMAND = "enter";
static const std::string VARS_COMMAND = "vars";
static const std::string PRINT_COMMAND = "print";
static const std::string LEAVES_COMMAND = "leaves";
static const std::string COMP_COMMAND = "comp";
static const std::string JOIN_COMMAND = "join";
static const std::string EXIT_COMMAND = "exit";

static const std::string UNKNOWN_COMMAND =
  "Unknown command. Type `" + LINE_PREFIX + "help` for usage information.\n";

static const std::string SKIPPING_TOKEN =
  "Skipping token: ";

static const std::string VAR_VALUE_NOT_FOUND =
  "Variable's value could not be resolved. Using 0 as a default value.\n";

static const std::string INVALID_CHAR =
  "Skipping invalid character in variable's name: ";

static const std::string VAR_NO_LETTER =
  "There's no letter in variable's name. Using default name instead.\n";

static const std::string NOT_ENOUGH_ARGS =
  "Not enough arguments. Using 0 as a default argument.\n";

static const std::string TOO_MANY_VARS =
  "Too many variables. Ignoring excessive values.\n";

static const std::string DIVISION_BY_ZERO =
  "Can't divide by zero! Evaluating division to 0 instead.\n";

class CLI
{
public:
  CLI();
  ~CLI();
  void run();
  static void printInfo(const std::string &info);

private:
  Tree *tree;

  static void printBanner();
  static void printHelp();
  void printVars() const;
  static void strip(std::string &str);
};

#endif
