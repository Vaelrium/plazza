//
// mutex.cpp for  in /home/ganesha/projets/plazza
//
// Made by Ambroise Coutarel
// Login   <ganesha@epitech.net>
//
// Started on  Fri Apr 17 11:42:48 2015 Ambroise Coutarel
// Last update Fri Apr 17 12:06:26 2015 Ambroise Coutarel
//

#include "mutex.hpp"

my_mutex::my_mutex()
{
  pthread_mutex_init(&mutex, NULL);
}

my_mutex::~my_mutex()
{
  pthread_mutex_destroy(&mutex);
}

int	my_mutex::lock()
{
  return (pthread_mutex_lock(&mutex));
}

int	my_mutex::unlock()
{
 return (pthread_mutex_unlock(&mutex));
}

int	my_mutex::trylock()
{
  return (pthread_mutex_trylock(&mutex));
}
