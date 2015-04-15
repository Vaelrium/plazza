//
// Parser.hpp for Parser in /home/collet_k/rendu/parser
// 
// Made by Kévin Colléter
// Login   <collet_k@epitech.net>
// 
// Started on  Tue Apr 14 11:49:21 2015 Kévin Colléter
// Last update Wed Apr 15 18:53:48 2015 Kévin Colléter
//

#ifndef PARSER_HPP_
# define PARSER_HPP

# define GOOD	0
# define ERROR	1
# define USAGE	"./plazza <multiplier cooking time> <number of cook> <time in milliseconds>"
# define ONLY_NBR "Error only positiv numbers"

#include <iostream>
#include <sstream>
#include <vector>
#include <string>

class Parser
{
public:
  Parser(int, char **);
  ~Parser();
  int	Check_Standard(int, char **);
  int	Print_Error(const char *) const;
  int	Is_Number(char *);
  int	Set_Value(char **);
  int	Read_Standard(void);
  int	Check_Command(std::string &);
  int	Nbr_Word(std::string &);
  void	Display(void) const;
  int	Check_Param1(std::string &);
  int	Check_Param2(std::string &);
  int	Check_Param3(std::string &);
  std::string	Set_Param(std::string &);

  /* Getter */
  int	get_argc(void) const;
  char	**get_argv(void) const;
  int	get_multi(void) const;
  int	get_cooks(void) const;
  int	get_time(void) const;
  std::vector<std::string> get_command(void) const;

private:
  char	**argv;
  int	argc;
  int	multi;
  int	cooks;
  int	time;
  const char	*type[4];
  const char	*size[5];
  std::vector<std::string> command;
};

# endif /* !PARSER_HPP_ */
