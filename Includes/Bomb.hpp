//
// Bomb_new.hpp for  in /home/vancom_l/rendu/CPP/hannot_bomberman/cpp_bomberman/Includes
// 
// Made by Lucas Vancompernolle
// Login   <vancom_l@epitech.net>
// 
// Started on  Thu Jun  5 12:56:38 2014 Lucas Vancompernolle
// Last update Sun Jun 15 23:14:47 2014 Lucas Vancompernolle
//

#ifndef			__BOMB_HPP__
# define		__BOMB_HPP__

# include		"Bonus.hpp"
# include		"Block.hpp"
# include		"Wall.hpp"
# include 		"Fire.hpp"

class			Bomb : public Block
{
private:
  int			idPlayer;
  int			power;
  double		destruction;
  double		start;
  double		_x_h;
  double		_x_l;
  double		_y_r;
  double		_y_l;
  std::vector<Fire *>	listFire;


public:
  Bomb(const glm::vec3 &, glm::vec3 const &, const int, const int);
  virtual		~Bomb();
  
  virtual bool		update(gdl::Clock &c);
  bool			check_wall_y(const size_t, const double, const double, const std::vector<Block *>&, std::vector<Bonus *> &);
  bool			check_wall_x(const size_t, const double, const double, const std::vector<Block *>&, std::vector<Bonus *> &);
  void			destroy(const std::vector<Block *> &, const std::vector<Block *> &, std::vector<Bonus *> &);

  void			setStart(const double);  
  std::vector<Fire *> 	getFire() const;
  double 		getStart() const;

  int			getId() const;
  int			getPower() const;
  double		getTimer() const;

  void			spawnBonus(const glm::vec3 &, std::vector<Bonus *> &);
};

#endif			/* __BOMB_HPP__ */
