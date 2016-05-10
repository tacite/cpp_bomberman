//
// Player.hpp for  in /home/vancom_l/rendu/CPP/hannot_bomberman/cpp_bomberman
// 
// Made by Lucas Vancompernolle
// Login   <vancom_l@epitech.net>
// 
// Started on  Thu Jun  5 15:07:37 2014 Lucas Vancompernolle
// Last update Sun Jun 15 23:25:51 2014 Lucas Vancompernolle
//

#ifndef PLAYER_HPP__
#define PLAYER_HPP__

#include "Block.hpp"
#include "Bonus.hpp"

class			Player
{
public:
  enum			e_type
  {
    HUMAN = 0,
    IA,
  };
  
protected:
  enum			e_dir
  {
    UP = 0,
    LEFT,
    DOWN,
    RIGHT
  };
  
protected:  
  float			speed;
  int			id;
  int			nbBomb;
  int			power;
  int			score;
  int			_number;
  std::string		name;
  std::string		asset;
  glm::vec3		_scale;
  glm::vec3		_rotation;
  glm::vec3		_position;
  gdl::Model		_model;
  e_dir			_dir;
  e_type		type;
  
public:
  Player(const glm::vec3 &, const std::string &, int number);
  virtual ~Player();
  
  virtual bool		initialize();
  virtual bool		update(gdl::AShader &, gdl::Clock const &, gdl::Input &, const std::vector<Block *> &, const std::vector<Block *> &, std::vector<Bonus *> &) = 0;
  void			draw(gdl::AShader &);
  glm::mat4		getTransformation();
  
  void			translate(glm::vec3 const &);
  void			rotate(glm::vec3 const &, float);
  void			scale(glm::vec3 const &);
  
  void 			setPos(const glm::vec3 &);
  void			setNbBomb(const int);
  void			setPower(const int);
  void			setSpeed(const float);
  void			setScore(const int);
  void 			setId(const int);
  
  const std::string &	getName() const;
  int			getId() const;
  Player::e_type	getType() const;

  double		getPosX() const;
  double		getPosY() const;
  double		getPosH() const;

  int			getNbBomb() const;
  int			getPower() const;
  float			getSpeed() const;
  int			getScore() const;
  
  void		setNumber(int);
  int		getNumber(void) const;

};

#endif
