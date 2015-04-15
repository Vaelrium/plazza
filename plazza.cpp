//
// plazza.cpp for plazza in /home/durand_u/github/plazza
//
// Made by Rémi DURAND
// Login   <durand_u@epitech.net>
//
// Started on  Wed Apr 15 09:50:44 2015 Rémi DURAND
// Last update Wed Apr 15 10:47:04 2015 Kévin Colléter
//

#include "Parser.hpp"
#include "plazza.hpp"

int		main(int ac, char **av)
{
  Parser	parser(ac, av);

  if (parser.Check_Standard(ac, av) == ERROR)
    return (ERROR);
  if (parser.Read_Standard() == ERROR)
    return (ERROR);
  return (0);
}
