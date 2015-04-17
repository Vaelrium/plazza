//
// condvar.hpp for  in /home/ganesha/projets/plazza
//
// Made by Ambroise Coutarel
// Login   <ganesha@epitech.net>
//
// Started on  Fri Apr 17 14:28:55 2015 Ambroise Coutarel
// Last update Fri Apr 17 15:34:06 2015 Ambroise Coutarel
//

#ifndef CONDVAR_HPP

# define CONDVAR_HPP

# include "plazza.hpp"

class	condvar
{
private:
  pthread_cond_t	cond;
public:
  condvar();
  ~condvar();
  int	signal();
  int	broadcast();
  int	wait(pthread_mutex_t *mutex);
  int	timedWait(pthread_mutex_t *mutex, time_t secs, long nanosecs);
};

#endif
