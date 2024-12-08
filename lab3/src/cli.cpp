#include "cli.h"

#include <iostream>

CLI::CLI()
{
  this->tree = new Tree();
}

CLI::~CLI()
{
  delete this->tree;
}

void CLI::run()
{
  printBanner();

  while (true)
  {
    std::cout << LINE_PREFIX;

    std::string input;
    std::getline(std::cin, input);

    std::string command = input.substr(0, input.find(' '));
    std::string arguments = input.substr(
      input.find(command) + command.length()
    );

    strip(arguments);

    if (command == HELP_COMMAND)
    {
      printHelp();
    }
    else if (command == ENTER_COMMAND)
    {
      this->tree->enterFormula(arguments);
    }
    else if (command == VARS_COMMAND)
    {
      this->printVars();
    }
    else if (command == PRINT_COMMAND)
    {
      if (!this->tree->empty())
      {
        std::cout << this->tree->repr() << "\n";
      }
    }
    else if (command == LEAVES_COMMAND)
    {
      std::cout << this->tree->leavesCount() << "\n";
    }
    else if (command == COMP_COMMAND)
    {
      std::map<std::string, uint8_t> vars;
      const std::set<std::string> varNames = this->tree->getVars();

      for (const std::string& varName : varNames)
      {
        strip(arguments);

        if (arguments.empty()) {
          vars[varName] = 0;
          printInfo(VAR_VALUE_NOT_FOUND);
        } else {
          vars[varName] = arguments[0] - '0';
        }

        if (!arguments.empty())
        {
          arguments = arguments.substr(1);
        }
      }

      strip(arguments);

      if (!arguments.empty())
      {
        std::cout << TOO_MANY_VARS;
      }

      this->tree->setVars(vars);

      std::cout << this->tree->eval() << "\n";
    }
    else if (command == JOIN_COMMAND)
    {
      Tree *newTree = new Tree();
      newTree->enterFormula(arguments);

      *this->tree = *this->tree + *newTree;

      delete newTree;
    }
    else if (command == EXIT_COMMAND)
    {
      break;
    }
    else
    {
      std::cout << UNKNOWN_COMMAND;
    }
  }
}

void CLI::printInfo(const std::string &info)
{
  std::cout << info;
}

void CLI::printBanner()
{
  std::cout << BANNER;
}

void CLI::printHelp()
{
  std::cout << HELP;
}

void CLI::printVars() const
{
  const std::set<std::string> varNames = this->tree->getVars();

  for (const std::string &varName : varNames)
  {
    std::cout << varName << " ";
  }

  if (!varNames.empty())
  {
    std::cout << "\n";
  }
}

void CLI::strip(std::string &str)
{
  str.erase(str.find_last_not_of(' ') + 1, std::string::npos);
  str.erase(0, std::min(str.find_first_not_of(' '), str.size() - 1));
}
