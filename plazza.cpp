//
// plazza.cpp for plazza in /home/durand_u/github/plazza
//
// Made by Rémi DURAND
// Login   <durand_u@epitech.net>
//
// Started on  Wed Apr 15 09:50:44 2015 Rémi DURAND
// Last update Tue Apr 21 11:20:28 2015 Rémi DURAND
//

#include "lobby.hpp"
#include "plazza.hpp"

int		algo_loop(Parser *parser)
{
  lobby		lobby(parser);

  lobby.create_new_kit();
  while (1)
    {
      if (parser->Read_Standard() == ERROR)
	return (ERROR);
      lobby.send_orders();
    }
}

int		main(int ac, char **av)
{
  Parser	parser(ac, av);

  if (parser.Check_Standard(ac, av) == ERROR)
    return (ERROR);
  algo_loop(&parser);
  return (0);
}
