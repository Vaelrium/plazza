//
// Parser.hpp for Parser in /home/collet_k/rendu/parser
// 
// Made by Kévin Colléter
// Login   <collet_k@epitech.net>
// 
// Started on  Tue Apr 14 11:49:21 2015 Kévin Colléter
// Last update Fri Apr 17 16:18:32 2015 Kévin Colléter
//

#ifndef PARSER_HPP_
# define PARSER_HPP

# define GOOD	0
# define ERROR	1
# define USAGE		"./plazza <multiplier cooking time> <number of cook> <time in milliseconds>"
# define ONLY_NBR	"Error arguments"
# define X_NBR		"x[numbers]"

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>

class Parser
{
public:
  Parser(int, char **);
  ~Parser();
  Parser &operator=(Parser const &);
  Parser(const Parser &);

  int	Check_Standard(const int, char **);
  int	Print_Error(const char *) const;
  int	Is_Number(const char *, const int) const;
  int	Set_Value(char **);
  int	Read_Standard(void);
  int	Check_Command(std::string &);
  int	Nbr_Word(const std::string &) const;
  int	Check_Param1(const std::string &) const;
  int	Check_Param2(const std::string &) const;
  int	Check_Param3(const std::string &) const;
  std::string	Set_Param(std::string &) const;
  void	Create_New_Command(const std::string &, const std::string &, const std::string &
);
  void	Delete_Command(void);

  /* Getter */
  int	get_argc(void) const;
  char	**get_argv(void) const;
  int	get_multi(void) const;
  int	get_cooks(void) const;
  int	get_time(void) const;
  std::vector<std::string> get_command(void) const;

private:
  char		**argv;
  int		argc;
  float		multi;
  unsigned int	cooks;
  unsigned int	time;
  const char	*type[4];
  const char	*size[5];
  std::vector<std::string> command;
};

# endif /* !PARSER_HPP_ */
