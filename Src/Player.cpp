/*
** Player.cpp for  in /home/roledg/CURRENT/cpp_bomberman/Src
** 
** Made by role-d_g
** Login   <roledg@epitech.net>
** 
** Started on  Fri Jun 13 20:12:10 2014 role-d_g
// Last update Sun Jun 15 19:49:44 2014 Hugo Houyez
*/

#include "Player.hpp"

Player::Player(const glm::vec3 &pos, const std::string &_name, int number)
{
  this->_number = number;
  this->_dir = Player::DOWN;
  this->_position = pos;
  this->speed = 10.0f;
  this->name = _name;
  this->id = -1;
  this->nbBomb = 1;
  this->power = 2;
  this->score = 0;
}

Player::~Player()
{
}

bool Player::initialize()
{
  if (this->_model.load(this->asset) == false)
    {
      std::cerr << "Can not load the model : " << this->asset << std::endl;
      return (false);
    }
  this->_model.setCurrentAnim(0, true);
  return (true);
}

void Player::draw(gdl::AShader &s)
{
  this->_model.draw(s, this->getTransformation(), GL_QUADS);
}

glm::mat4 Player::getTransformation()
{
  glm::mat4		transform(1);

  transform = glm::translate(transform, this->_position);
  transform = glm::rotate(transform, this->_rotation.x, glm::vec3(1, 0, 0));
  transform = glm::rotate(transform, this->_rotation.y, glm::vec3(0, 1, 0));
  transform = glm::rotate(transform, this->_rotation.z, glm::vec3(0, 0, 1));
  transform = glm::scale(transform, this->_scale);
  return (transform);
}

void Player::translate(glm::vec3 const &v)
{
  this->_position += v;
}

void Player::rotate(glm::vec3 const &v, float a)
{
  this->_rotation += (v * a);
}

void Player::scale(glm::vec3 const &v)
{
  this->_scale += v;
}

const std::string &	Player::getName() const
{
  return name;
}

int			Player::getId() const
{
  return id;
}

Player::e_type		Player::getType() const
{
  return type;
}

double			Player::getPosX() const
{
  return this->_position.x;
}

double			Player::getPosY() const
{
  return this->_position.y;
}

double			Player::getPosH() const
{
  return this->_position.z;
}

int			Player::getNbBomb() const
{
  return nbBomb;
}

int			Player::getPower() const
{
  return power;
}

float			Player::getSpeed() const
{
  return speed;
}

int			Player::getScore() const
{
  return score;
}

void			Player::setPos(const glm::vec3 &pos)
{
  this->_position = pos;
}

void			Player::setNbBomb(const int _nbBomb)
{
  nbBomb = _nbBomb;
}

void			Player::setPower(const int _power)
{
  power = _power;
}

void			Player::setSpeed(const float _speed)
{
  speed = _speed;
}

void			Player::setScore(const int _score)
{
  score = _score;
}

void			Player::setId(const int _id)
{
  this->id = _id;
}

void			Player::setNumber(int number)
{
 this->_number = number; 
}

int			Player::getNumber(void) const
{
  return (this->_number);
}
