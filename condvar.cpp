//
// condvar.cpp for  in /home/ganesha/projets/plazza
//
// Made by Ambroise Coutarel
// Login   <ganesha@epitech.net>
//
// Started on  Fri Apr 17 14:29:06 2015 Ambroise Coutarel
// Last update Fri Apr 17 15:37:14 2015 Ambroise Coutarel
//

#include "condvar.hpp"

condvar::condvar()
{
  pthread_cond_init(&cond, NULL);
}

condvar::~condvar()
{
  pthread_cond_destroy(&cond);
}

int	condvar::signal()
{
  return (pthread_cond_signal(&cond));
}

int	condvar::broadcast()
{
  return (pthread_cond_broadcast(&cond));
}

int	condvar::wait(pthread_mutex_t *mutex)
{
  return (pthread_cond_wait(&cond, mutex));
}

int	condvar::timedWait(pthread_mutex_t *mutex, time_t secs, long nanosecs)
{
  struct timespec	duration;

  duration.tv_sec = secs;
  duration.tv_nsec = nanosecs;
  return (pthread_cond_timedwait(&cond, mutex, &duration));
}
