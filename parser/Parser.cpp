//
// Parser.cpp for Parser in /home/collet_k/rendu/parser
//
// Made by Kévin Colléter
// Login   <collet_k@epitech.net>
//
// Started on  Tue Apr 14 11:49:29 2015 Kévin Colléter
// Last update Wed Apr 15 10:16:38 2015 Kévin Colléter
//

#include "Parser.hpp"

Parser::Parser(int ac, char **av)
{
  this->argc = ac;
  this->argv = av;
  this->multi = 0;
  this->cooks = 0;
  this->time = 0;
}

Parser::~Parser()
{}

int	Parser::Print_Error(const char *msg) const
{
  std::cerr << msg << std::endl;
  return (ERROR);
}

int	Parser::Check_Standard(int ac, char **av)
{
  if (ac != 4)
    return (Print_Error(USAGE));
  for (int i = 1; i < 4; i++)
    if (Is_Number(av[i]) == ERROR)
      return (Print_Error(ONLY_NBR));
  Set_Value(av);
  return (GOOD);
}

int	Parser::Is_Number(char *nbr)
{
  for (int i = 0; nbr[i] != '\0'; i++)
    if (nbr[i] < '0' || nbr[i] > '9')
      return (ERROR);
  return (GOOD);
}

int	Parser::Set_Value(char **av)
{
  std::stringstream	str_multi;
  std::stringstream	str_cooks;
  std::stringstream	str_time;

  str_multi << av[1];
  str_multi >> this->multi;
  str_cooks << av[2];
  str_cooks >> this->cooks;
  str_time << av[3];
  str_time >> this->time;
}

int	Parser::Read_Standard(void)
{
  std::string	cmd;
  std::string	delimiter = ";";
  std::string	token;
  size_t	pos = 0;

  while (42)
    {
      std::cout << "\033[1;36mQue voulez vous ?\n\033[00m-> ";
      std::getline(std::cin, cmd);
      while ((pos = cmd.find(delimiter)) != std::string::npos) {
	token = cmd.substr(0, pos);
	command.push_back(token);
	cmd.erase(0, pos + 1);
      }
      command.push_back(cmd);
      cmd.clear();
      Check_Command();
    }
  return (GOOD);
}

int	Parser::Check_Command(void)
{
  return (GOOD);
}

void	Parser::Display(void) const
{
  for (int i = 0; i < command.size(); i++)
    std::cout << "- " << command[i] << std::endl;
}

int	Parser::get_argc(void) const
{
  return (this->argc);
}

char	**Parser::get_argv(void) const
{
  return (this->argv);
}

int	Parser::get_multi(void) const
{
  return (this->multi);
}

int	Parser::get_cooks(void) const
{
  return (this->cooks);
}

int	Parser::get_time(void) const
{
  return (this->time);
}

std::vector<std::string>	Parser::get_command(void) const
{
  return (this->command);
}
