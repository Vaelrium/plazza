//
// processes.hpp for proc in /home/durand_u/github/plazza
// 
// Made by Rémi DURAND
// Login   <durand_u@epitech.net>
// 
// Started on  Wed Apr 15 11:29:03 2015 Rémi DURAND
// Last update Tue Apr 21 11:21:29 2015 Rémi DURAND
//

#ifndef _PRO_H_
# define _PRO_H_
# include "thread.hpp"
# include "plazza.hpp"

class		proc_kit
{
private:
  int			_nb_cooks;
  int			_cook_time;
  int			_free_cooks;
  float			_multiplier;
  int			_fd_in;
  int			_fd_out;
  std::vector<thread*>	cooks;
public:
  proc_kit(int nb_cooks, int cook_time, float multiplier, std::string &id);
  ~proc_kit();
};

#endif
