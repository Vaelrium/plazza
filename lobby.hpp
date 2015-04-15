//
// lobby.hpp for lobby in /home/durand_u/github/plazza
// 
// Made by Rémi DURAND
// Login   <durand_u@epitech.net>
// 
// Started on  Wed Apr 15 10:37:43 2015 Rémi DURAND
// Last update Wed Apr 15 11:20:53 2015 Rémi DURAND
//

#ifndef _LOB_H_
# define _LOB_H_

class		lobby
{
private:
  Parser	*pars;
  int		nb_kit;
  int		last_kit;
  int		max_kit;
  std::vector<std::pair<int, int> >	npipes;
public:
  lobby();
  ~lobby();
  lobby(const lobby&);
  lobby&	operator=(const lobby&);
  void		create_new_kit();
  void		display_kit_stats();
  void		send_orders();
  void		display_order_ready();
  void		add_log();
};

#endif
