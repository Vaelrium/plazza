//
// mutex.hpp for  in /home/ganesha/projets/plazza
//
// Made by Ambroise Coutarel
// Login   <ganesha@epitech.net>
//
// Started on  Fri Apr 17 11:37:32 2015 Ambroise Coutarel
// Last update Fri Apr 17 12:02:33 2015 Ambroise Coutarel
//

#ifndef MUTEX_HPP

#define MUTEX_HPP

#include "plazza.hpp"

class	my_mutex
{
private:
  pthread_mutex_t	mutex;

public:
  my_mutex();
  ~my_mutex();
  int	lock();
  int	unlock();
  int	trylock();
};

#endif
