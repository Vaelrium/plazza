//
// lobby.cpp for looby in /home/durand_u/github/plazza
// 
// Made by Rémi DURAND
// Login   <durand_u@epitech.net>
// 
// Started on  Wed Apr 15 10:56:13 2015 Rémi DURAND
// Last update Tue Apr 21 11:10:36 2015 Rémi DURAND
//

#include "lobby.hpp"

lobby::lobby(Parser *parser)
{
  pars = parser;
  last_kit = 0;
  max_kit = 1;
}

lobby::~lobby()
{
}


lobby::lobby(const lobby& other)
{
  pars = other.getPars();
  last_kit = other.getLast();
  max_kit = other.getMax();
  npipes = other.getNpipe();
}

lobby&			lobby::operator=(const lobby& other)
{
  if (this != &other)
    {
      pars = other.getPars();
      last_kit = other.getLast();
      max_kit = other.getMax();
      npipes = other.getNpipe();
    }
  return (*this);
}

void			lobby::create_new_kit()
{
  int			proc_in;
  int			proc_out;
  std::stringstream	ss;
  ss << (++this->max_kit);
  std::string		id(ss.str());
  pid_t			pid;

  mkfifo(id.c_str(), 0);
  id.append("2");
  mkfifo(id.c_str(), 0);
  proc_out = open(id.c_str(), O_RDONLY);
  id.erase(id.length() - 1, 1);
  proc_in = open(id.c_str(), O_WRONLY);
  this->npipes[this->last_kit - 1] = std::make_pair(proc_in, proc_out);
  pid = fork();
  if (pid == 0)
    {
      proc_kit	new_proc(this->pars->get_cooks(), this->pars->get_time(), this->pars->get_multi(), id);
      exit(1);
    }
}

void				lobby::send_orders()
{
  std::vector<std::string>	commands;
  unsigned int			v;
  char				rep[2];

  v = 0;
  commands = this->pars->get_command();
  while (v != commands.size())
    {
      write(this->npipes[this->last_kit].first, "7777", 4);
      read(this->npipes[this->last_kit].second, rep, 2);
      if (rep[0] == 'n' && rep[1] == 'o')
	this->create_new_kit();
      else
	{
	  write(this->npipes[this->last_kit].first, commands[v].c_str(), commands[v].length());
	  this->pars->Delete_Command();
	  ++v;
	}
      if (this->last_kit == this->max_kit)
	this->last_kit = 0;
      else
	++this->last_kit;
    }
}

Parser		*lobby::getPars() const
{
  return (pars);
}

int		lobby::getLast() const
{
  return (last_kit);
}

int		lobby::getMax() const
{
  return (max_kit);
}

pipetab		lobby::getNpipe() const
{
  return (npipes);
}

void		lobby::setPars(Parser *neww)
{
  pars = neww;
}

void		lobby::setLast(int neww)
{
  last_kit = neww;
}

void		lobby::setMax(int neww)
{
  max_kit = neww;
}

void		lobby::setNpipe(pipetab neww)
{
  npipes = neww;
}
