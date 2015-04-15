//
// Parser.cpp for Parser in /home/collet_k/rendu/parser
//
// Made by Kévin Colléter
// Login   <collet_k@epitech.net>
//
// Started on  Tue Apr 14 11:49:29 2015 Kévin Colléter
// Last update Wed Apr 15 19:10:57 2015 Kévin Colléter
//

#include "Parser.hpp"

Parser::Parser(int ac, char **av)
{
  this->argc = ac;
  this->argv = av;
  this->multi = 0;
  this->cooks = 0;
  this->time = 0;

  this->type[0] = "Regina";
  this->type[1] = "Margarita";
  this->type[2] = "Americaine";
  this->type[3] = "Fantasia";

  this->size[0] = "S";
  this->size[1] = "M";
  this->size[2] = "L";
  this->size[3] = "XL";
  this->size[4] = "XXL";
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
  return (GOOD);
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
	Check_Command(token);
	cmd.erase(0, pos + 1);
      }
      Check_Command(cmd);
      cmd.clear();
    }
  return (GOOD);
}

int	Parser::Check_Command(std::string &token)
{
  std::string	param1;
  std::string	param2;
  std::string	param3;
  std::string	delimiter = " ";

  if (Nbr_Word(token) != 3) {
    std::cerr << "[" << token << "]";
    return (Print_Error(" : Error <Which Type> <Which Size> <How Many>"));
  }
  param1 = Set_Param(token);
  param2 = Set_Param(token);
  param3 = Set_Param(token);
  if ((Check_Param1(param1) == ERROR) ||
      (Check_Param2(param2) == ERROR) ||
      (Check_Param3(param3) == ERROR))
    return (ERROR);
  this->command.push_back(param1 + " " + param2 + " " + param3);
  return (GOOD);
}

std::string	Parser::Set_Param(std::string &token)
{
  int		i = 0;
  std::string	ret;

  while ((token[i] == ' ' || token[i] == '\t') && token[i] != '\0')
    ++i;
  while (token[i] != ' ' && token[i] != '\t' && token[i] != '\0')
    ret += token[i++];
  token.erase(0, i);
  return (ret);
}

int	Parser::Check_Param1(std::string &token)
{
  for (int i = 0; i < 4; i++)
    if (token.compare(this->type[i]) == 0)
      return (GOOD);
  std::cerr << "Type : [" << token;
  return (Print_Error("] don't find"));
}

int	Parser::Check_Param2(std::string &token)
{
  for (int i = 0; i < 5; i++)
    if (token.compare(this->size[i]) == 0)
      return (GOOD);
  std::cerr << "Syze : [" << token;
  return (Print_Error("] don't find"));
}

int	Parser::Check_Param3(std::string &token)
{
  if (token[0] != 'x')
    {
      std::cerr << "Bad usage [" << token << "]\nUsage : ";
      return (Print_Error("x[numbers]"));
    }
  for (unsigned int i = 1; i != token.size(); i++)
    if (token[i] < '0' || token[i] > '9')
      {
	std::cerr << "Bad usage [" << token << "]\nUsage : ";
	return (Print_Error("x[numbers]"));
      }
  return (GOOD);
}

int	Parser::Nbr_Word(std::string &token)
{
  int	i = 0;
  int	count = 0;

  while (token[i] != 0)
    {
      while ((token[i] == ' ' || token[i] == '\t') && token[i] != '\0')
	++i;
      if (token[i] == 0)
	return (count);
      while (token[i] != ' ' && token[i] != '\t' && token[i] != '\0')
	++i;
      ++count;
    }
  return (count);
}

void	Parser::Display(void) const
{
  std::cout << "\033[1;31mEn cours :\033[00m" << std::endl;
  for (unsigned int i = 0; i < command.size(); i++)
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
