//
// mutex.cpp for  in /home/ganesha/projets/plazza
//
// Made by Ambroise Coutarel
// Login   <ganesha@epitech.net>
//
// Started on  Fri Apr 17 11:42:48 2015 Ambroise Coutarel
// Last update Fri Apr 17 11:49:31 2015 Ambroise Coutarel
//

#include "mutex.hpp"

mutex::mutex()
{
  mutex = PHTREAD_MUTEX_INITIALIZER;
}

mutex::~mutex()
{
  pthread_mutex_destroy(mutex);
}

int	mutex::lock()
{
  return (pthread_mutex_lock(mutex));
}

int	mutex::unlock()
{
 return (pthread_mutex_unlock(mutex));
}

int	mutex::trylock()
{
  return (pthread_mutex_trylock(mutex));
}
