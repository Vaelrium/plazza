//
// thread.hpp for  in /home/ganesha/projets/plazza
//
// Made by Ambroise Coutarel
// Login   <ganesha@epitech.net>
//
// Started on  Fri Apr 17 10:07:56 2015 Ambroise Coutarel
// Last update Fri Apr 17 11:02:56 2015 Ambroise Coutarel
//

#indef THREAD_HPP_

# define THREAD_HPP_

# include <pthread.h>

class	thread
{
private:
  pthread_t	_thread;

public:
  thread::thread();
  thread::~thread();
  void	thread_execute(void *(*routine) (void*), void *arg);
};

#endif /* !THREAD_HPP_ */
