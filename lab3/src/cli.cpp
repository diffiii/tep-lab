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

void CLI::run() const
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

    if (command == "help")
    {
      printHelp();
    }
    else if (command == "enter")
    {
      this->tree->enterFormula(arguments);
    }
    else if (command == "vars")
    {
      this->printVars();
    }
    else if (command == "print")
    {
      if (!this->tree->empty())
      {
        std::cout << this->tree->repr() << "\n";
      }
    }
    else if (command == "comp")
    {
      std::map<std::string, uint8_t> vars;
      const std::set<std::string> varNames = this->tree->getVars();

      for (const std::string& varName : varNames)
      {
        strip(arguments);

        vars[varName] = arguments.empty() ? 0 : arguments[0] - '0';

        if (arguments.length() > 1)
        {
          arguments = arguments.substr(2);
        }
      }

      arguments = arguments.substr(1);

      if (!arguments.empty())
      {
        std::cout << TOO_MANY_VARS;
      }

      this->tree->setVars(vars);

      std::cout << this->tree->eval() << "\n";
    }
    else if (command == "join")
    {
      // TODO
    }
    else if (command == "exit")
    {
      break;
    }
    else
    {
      std::cout << UNKNOWN_COMMAND;
    }
  }
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
