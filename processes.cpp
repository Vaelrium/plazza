//
// processes.cpp for plazza pizza pie in /home/ganesha/projets/plazza
//
// Made by Ambroise Coutarel
// Login   <ganesha@epitech.net>
//
// Started on  Thu Apr 16 16:49:36 2015 Ambroise Coutarel
// Last update Fri Apr 17 16:49:19 2015 Rémi DURAND
//

#include "processes.hpp"

proc_kit::proc_kit(int nb_cooks, int cook_time, float multiplier, std::string &id)
{
  _nb_cooks = nb_cooks;
  _cook_time = cook_time;
  _multiplier = multiplier;
  _fd_in = open(id.c_str(), O_RDONLY);
  id.append("2");
  _fd_out = open(id.c_str(), O_WRONLY);
  for (int i = 0; i != nb_cooks ; i++)
    {
      cooks.push_back(new thread);
    }
}

proc_kit::~proc_kit()
{
  cooks.clear();
  close(_fd_in);
  close(_fd_out);
}
