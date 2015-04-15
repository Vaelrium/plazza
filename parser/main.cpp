#include <iostream>
#include "Parser.hpp"

int		main(int argc, char **argv)
{
  Parser	parser(argc, argv);

  if (parser.Check_Standard(argc, argv) == ERROR)
    return (ERROR);

  //initialisation des threads..

  if (parser.Read_Standard() == ERROR)
    return (ERROR);
}
