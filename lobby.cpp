//
// lobby.cpp for looby in /home/durand_u/github/plazza
// 
// Made by Rémi DURAND
// Login   <durand_u@epitech.net>
// 
// Started on  Wed Apr 15 10:56:13 2015 Rémi DURAND
// Last update Fri Apr 17 14:27:00 2015 Rémi DURAND
//

#include "lobby.hpp"

void			lobby::create_new_kit()
{
  int			proc_in;
  int			proc_out;
  std::stringstream	ss;
  ss << (++this->last_kit);
  std::string		id(ss.str());
  pid_t			pid;

  mkfifo(id.c_str(), 0);
  id.append("2");
  mkfifo(id.c_str(), 0);
  proc_out = open(id.c_str(), O_RDONLY);
  id.erase(id.length() - 1, 1);
  proc_in = open(id.c_str(), O_WRONLY);
  this->npipes[this->last_kit - 1] = std::make_pair(proc_in, proc_out);
  pid = fork();
  if (pid == 0)
    {
      proc_kit	new_proc(this->pars->get_cooks(), this->pars->get_time(), this->pars->get_multi(), id);
      exit(1);
    }
}
