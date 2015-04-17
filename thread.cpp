//
// thread.cpp for  in /home/ganesha/projets/plazza
//
// Made by Ambroise Coutarel
// Login   <ganesha@epitech.net>
//
// Started on  Fri Apr 17 10:30:01 2015 Ambroise Coutarel
// Last update Fri Apr 17 11:01:27 2015 Ambroise Coutarel
//

#include "thread.hpp"

thread::thread()
{
  _thread = NULL;
}

thread::~thread()
{
  if (_thread)
    pthread_exit();
}

void	thread::thread_execute(void *(*routine) (void*), void *arg)
{
  pthread_create(_thread, NULL, routine, arg);
}
