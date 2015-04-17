//
// mutex.hpp for  in /home/ganesha/projets/plazza
//
// Made by Ambroise Coutarel
// Login   <ganesha@epitech.net>
//
// Started on  Fri Apr 17 11:37:32 2015 Ambroise Coutarel
// Last update Fri Apr 17 11:48:18 2015 Ambroise Coutarel
//

#ifndef MUTEX_HPP

#define MUTEX_HPP

#include "plazza.hpp"
class	MUTEX_HPP
{
private:
  pthread_mutex_t	mutex;

public:
  mutex();
  ~mutex();
  int	lock();
  int	unlock();
  int	trylock();
}

#endif
