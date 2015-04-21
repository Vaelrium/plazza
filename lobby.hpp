//
// lobby.hpp for lobby in /home/durand_u/github/plazza
// 
// Made by Rémi DURAND
// Login   <durand_u@epitech.net>
// 
// Started on  Wed Apr 15 10:37:43 2015 Rémi DURAND
// Last update Tue Apr 21 11:56:39 2015 Rémi DURAND
//

#ifndef _LOB_H_
# define _LOB_H_

# include "plazza.hpp"
# include "Parser.hpp"
# include "processes.hpp"

typedef std::vector<std::pair<int, int> > pipetab;

char		g_pizzas[4][11] = {"Regina", "Margarita", "Americaine", "Fantasia"};

class		lobby
{
private:
  Parser	*pars;
  int		last_kit;
  int		max_kit;
  pipetab	npipes;
public:
  lobby(Parser *);
  ~lobby();
  lobby(const lobby&);
  lobby&	operator=(const lobby&);
  void		create_new_kit();
  void		display_kit_stats();
  void		send_orders();
  void		display_order_ready();
  void		add_log();

  Parser	*getPars() const;
  int		getLast() const;
  int		getMax() const;
  pipetab	getNpipe() const;
  void		setPars(Parser *);
  void		setLast(int);
  void		setMax(int);
  void		setNpipe(pipetab);
};

#endif
