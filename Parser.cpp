//
// Parser.cpp for Parser in /home/collet_k/rendu/parser
//
// Made by Kévin Colléter
// Login   <collet_k@epitech.net>
//
// Started on  Tue Apr 14 11:49:29 2015 Kévin Colléter
// Last update Fri Apr 17 16:26:43 2015 Kévin Colléter
//

#include "Parser.hpp"

Parser::Parser(int ac, char **av)
{
  this->argc = ac;
  this->argv = av;
  this->multi = 0;
  this->cooks = 0;
  this->time = 0;

  this->type[0] = "regina";
  this->type[1] = "margarita";
  this->type[2] = "americaine";
  this->type[3] = "fantasia";

  this->size[0] = "S";
  this->size[1] = "M";
  this->size[2] = "L";
  this->size[3] = "XL";
  this->size[4] = "XXL";
}

Parser::Parser(const Parser &copy)
{
  this->argc = copy.get_argc();
  this->argv = copy.get_argv();
  this->multi = copy.get_multi();
  this->time = copy.get_time();
  this->cooks = copy.get_cooks();
  this->command = copy.get_command();
}

Parser	&Parser::operator=(Parser const &other)
{
  if (this != &other)
    {
      this->argc = other.get_argc();
      this->argv = other.get_argv();
      this->multi = other.get_multi();
      this->time = other.get_time();
      this->cooks = other.get_cooks();
      this->command = other.get_command();
    }
  return (*this);
}

Parser::~Parser()
{}

int	Parser::Print_Error(const char *msg) const
{
  std::cerr << msg << std::endl;
  return (ERROR);
}

int	Parser::Check_Standard(const int ac, char **av)
{
  if (ac != 4)
    return (Print_Error(USAGE));
  if (Is_Number(av[1], 1) == ERROR)
    return (Print_Error(ONLY_NBR));
  for (unsigned int i = 2; i < 4; i++)
    if (Is_Number(av[i], 0) == ERROR)
      return (Print_Error(ONLY_NBR));
  Set_Value(av);
  return (GOOD);
}

int	Parser::Is_Number(const char *nbr, const int max) const
{
  int	nbr_point = 0;

  for (unsigned int i = 0; nbr[i] != '\0'; i++) {
    if ((nbr[i] < '0' || nbr[i] > '9') && nbr[i] != '.')
      return (ERROR);
    if (nbr[i] == '.')
      ++nbr_point;
  }
  if (nbr_point > max) {
    std::cerr << "Error '.' in " << nbr << std::endl;
    return (ERROR);
  }
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
  std::transform(param1.begin(), param1.end(), param1.begin(), ::tolower);
  if ((Check_Param1(param1) == ERROR) ||
      (Check_Param2(param2) == ERROR) ||
      (Check_Param3(param3) == ERROR))
    return (ERROR);
  Create_New_Command(param1, param2, param3);
  return (GOOD);
}

std::string	Parser::Set_Param(std::string &token) const
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

int	Parser::Check_Param1(const std::string &token) const
{
  for (int i = 0; i < 4; i++)
    if (token.compare(this->type[i]) == 0)
      return (GOOD);
  std::cerr << "Type : [" << token;
  return (Print_Error("] don't find"));
}

int	Parser::Check_Param2(const std::string &token) const
{
  for (int i = 0; i < 5; i++)
    if (token.compare(this->size[i]) == 0)
      return (GOOD);
  std::cerr << "Syze : [" << token;
  return (Print_Error("] don't find"));
}

int	Parser::Check_Param3(const std::string &token) const
{
  if (token[0] != 'x')
    {
      std::cerr << "Bad usage [" << token << "]\nUsage : ";
      return (Print_Error(X_NBR));
    }
  for (unsigned int i = 1; i != token.size(); i++)
    if (token[i] < '0' || token[i] > '9')
      {
	std::cerr << "Bad usage [" << token << "]\nUsage : ";
	return (Print_Error(X_NBR));
      }
  return (GOOD);
}

void	Parser::Create_New_Command(const std::string &param1, const std::string &param2, const std::string &param3)
{
  std::istringstream buffer(&param3[1]);
  unsigned int counter;

  buffer >> counter;
  for (unsigned int i = 0; i != counter; i++)
    this->command.push_back(param1 + " " + param2);
}

void	Parser::Delete_Command()
{
  if (this->command.empty() != 0)
    this->command.erase(command.begin());
}

int	Parser::Nbr_Word(const std::string &token) const
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
