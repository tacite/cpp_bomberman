/*
** Human.cpp for  in /home/roledg/CURRENT/cpp_bomberman
** 
** Made by role-d_g
** Login   <roledg@epitech.net>
** 
** Started on  Fri Jun 13 20:17:07 2014 role-d_g
// Last update Sun Jun 15 23:25:04 2014 Lucas Vancompernolle
*/

#include	"Human.hpp"

Human::Human(const glm::vec3 &pos, const std::string &_name, int number) :
  Player(pos, _name, number)
{
  this->_scale = glm::vec3(0.002, 0.002, 0.002);
  this->_rotation = glm::vec3(90, 0, 0);
  this->asset = "./Assets/human.fbx";
  this->id = 1;
  this->nbBomb = 2;
  this->type = Player::HUMAN;
}

Human::~Human()
{
}

bool			Human::update(gdl::AShader &s, const gdl::Clock &c, gdl::Input &i, const std::vector<Block *> &list, const std::vector<Block *> &wall, std::vector<Bonus *> &listBonus)
{
  glm::mat4		transformation;

  transformation = glm::lookAt(glm::vec3(this->_position.x, this->_position.y - 3, 5), glm::vec3(this->_position.x, this->_position.y, this->_position.z), glm::vec3(0, 1, 0));
  s.setUniform("view", transformation);
  if (this->_number == 0)
    {
      if (i.getKey(SDLK_DOWN))
	{
	  double	x = round(this->_position.x);
	  double	y = round(this->_position.y - 0.5);
	  for (double i = 0; i < list.size(); ++i)
	    {
	      if (x == round(list[i]->getPos().x) && y == round(list[i]->getPos().y) && this->_position.z == list[i]->getPos().z)
		return (true);
	    }
	  for (double i = 0; i < wall.size(); ++i)
	    {
	      if (x == round(wall[i]->getPos().x) && y == round(wall[i]->getPos().y) && this->_position.z == wall[i]->getPos().z)
		return (true);
	    }
	  for (double i = 0; i < listBonus.size(); i++)
	    {
	      if (x == round(listBonus[i]->getPos().x) && y == round(listBonus[i]->getPos().y))
		{
		  this->pickUpBonus(listBonus, i);
		}
	    }
	  switch (this->_dir)
	    {
	    case Player::UP:
	      this->rotate(glm::vec3(0, -1, 0), 180);
	      break;
	    case Player::LEFT:
	      this->rotate(glm::vec3(0, -1, 0), 270);
	      break;
	    case Player::RIGHT:
	      this->rotate(glm::vec3(0, -1, 0), 90);
	      break;
	    }
	  this->_dir = Player::DOWN;      
	  this->translate(glm::vec3(0, -1, 0) * static_cast<float>(c.getElapsed()) * this->speed);
	}
      if (i.getKey(SDLK_UP))
	{
	  double	x = round(this->_position.x);
	  double	y = round(this->_position.y + 0.5);
 
	  for (double i = 0; i < list.size(); ++i)
	    {
	      if (x == round(list[i]->getPos().x) && y == round(list[i]->getPos().y) && this->_position.z == list[i]->getPos().z)
		return (true);
	    }
	  for (double i = 0; i < wall.size(); ++i)
	    {
	      if (x == round(wall[i]->getPos().x) && y == round(wall[i]->getPos().y) && this->_position.z == wall[i]->getPos().z)
		return (true);
	    }
	  for (double i = 0; i < listBonus.size(); i++)
	    if (x == round(listBonus[i]->getPos().x) && y == round(listBonus[i]->getPos().y))
	      this->pickUpBonus(listBonus, i);
	  switch (this->_dir)
	    {
	    case Player::DOWN:
	      this->rotate(glm::vec3(0, -1, 0), 180);
	      break;
	    case Player::LEFT:
	      this->rotate(glm::vec3(0, -1, 0), 90);
	      break;
	    case Player::RIGHT:
	      this->rotate(glm::vec3(0, -1, 0), 270);
	      break;
	    }
	  this->_dir = Player::UP;    
	  this->translate(glm::vec3(0, 1, 0) * static_cast<float>(c.getElapsed()) * this->speed);
	}
      if (i.getKey(SDLK_RIGHT))
	{
	  double	x = round(this->_position.x + 0.5);
	  double	y = round(this->_position.y);

	  for (double i = 0; i < list.size(); ++i)
	    {
	      if (x == round(list[i]->getPos().x) && y == round(list[i]->getPos().y) && this->_position.z == list[i]->getPos().z)
		return (true);
	    }
	  for (double i = 0; i < wall.size(); ++i)
	    {
	      if (x == round(wall[i]->getPos().x) && y == round(wall[i]->getPos().y) && this->_position.z == wall[i]->getPos().z)
		return (true);
	    }    
	  for (double i = 0; i < listBonus.size(); i++)
	    if (x == round(listBonus[i]->getPos().x) && y == round(listBonus[i]->getPos().y))
	      this->pickUpBonus(listBonus, i);
	  switch (this->_dir)
	    {
	    case Player::UP:
	      this->rotate(glm::vec3(0, -1, 0), 90);
	      break;
	    case Player::LEFT:
	      this->rotate(glm::vec3(0, -1, 0), 180);
	      break;
	    case Player::DOWN:
	      this->rotate(glm::vec3(0, -1, 0), 270);
	      break;
	    }
	  this->_dir = Player::RIGHT;    
	  this->translate(glm::vec3(1, 0, 0) * static_cast<float>(c.getElapsed()) * this->speed);
	}
      if (i.getKey(SDLK_LEFT))
	{
	  double	x = round(this->_position.x - 0.5);
	  double	y = round(this->_position.y);

	  for (double i = 0; i < list.size(); ++i)
	    {
	      if (x == round(list[i]->getPos().x) && y == round(list[i]->getPos().y) && this->_position.z == list[i]->getPos().z)
		return (true);
	    }
	  for (double i = 0; i < wall.size(); ++i)
	    {
	      if (x == round(wall[i]->getPos().x) && y == round(wall[i]->getPos().y) && this->_position.z == wall[i]->getPos().z)
		return (true);
	    }
	  for (double i = 0; i < listBonus.size(); i++)
	    if (x == round(listBonus[i]->getPos().x) && y == round(listBonus[i]->getPos().y))
	      this->pickUpBonus(listBonus, i);
	  switch (this->_dir)
	    {
	    case Player::RIGHT:
	      this->rotate(glm::vec3(0, -1, 0), 180);
	      break;
	    case Player::UP:
	      this->rotate(glm::vec3(0, -1, 0), 270);
	      break;
	    case Player::DOWN:
	      this->rotate(glm::vec3(0, -1, 0), 90);
	      break;
	    }
	  this->_dir = Player::LEFT;
	  this->translate(glm::vec3(-1, 0, 0) * static_cast<float>(c.getElapsed()) * this->speed);
	}
    }  
  if (this->_number == 1)
    {
      if (i.getKey(SDLK_s))
	{
	  double	x = round(this->_position.x);
	  double	y = round(this->_position.y - 0.5);

	  for (double i = 0; i < list.size(); ++i)
	    {
	      if (x == round(list[i]->getPos().x) && y == round(list[i]->getPos().y) && this->_position.z == list[i]->getPos().z)
		return (true);
	    }

	  for (double i = 0; i < wall.size(); ++i)
	    {
	      if (x == round(wall[i]->getPos().x) && y == round(wall[i]->getPos().y) && this->_position.z == wall[i]->getPos().z)
		return (true);
	    }
	  for (double i = 0; i < listBonus.size(); i++)
	    if (x == round(listBonus[i]->getPos().x) && y == round(listBonus[i]->getPos().y))
	      this->pickUpBonus(listBonus, i);
	  switch (this->_dir)
	    {
	    case Player::UP:
	      this->rotate(glm::vec3(0, -1, 0), 180);
	      break;
	    case Player::LEFT:
	      this->rotate(glm::vec3(0, -1, 0), 270);
	      break;
	    case Player::RIGHT:
	      this->rotate(glm::vec3(0, -1, 0), 90);
	      break;
	    }
	  this->_dir = Player::DOWN;      
	  this->translate(glm::vec3(0, -1, 0) * static_cast<float>(c.getElapsed()) * this->speed);
	}
      if (i.getKey(SDLK_z))
	{
	  double	x = round(this->_position.x);
	  double	y = round(this->_position.y + 0.5);

	  for (double i = 0; i < list.size(); ++i)
	    {
	      if (x == round(list[i]->getPos().x) && y == round(list[i]->getPos().y) && this->_position.z == list[i]->getPos().z)
		return (true);
	    }        
	  for (double i = 0; i < wall.size(); ++i)
	    {
	      if (x == round(wall[i]->getPos().x) && y == round(wall[i]->getPos().y) && this->_position.z == wall[i]->getPos().z)
		return (true);
	    }
	  for (double i = 0; i < listBonus.size(); i++)
	    if (x == round(listBonus[i]->getPos().x) && y == round(listBonus[i]->getPos().y))
	      this->pickUpBonus(listBonus, i);
	  switch (this->_dir)
	    {
	    case Player::DOWN:
	      this->rotate(glm::vec3(0, -1, 0), 180);
	      break;
	    case Player::LEFT:
	      this->rotate(glm::vec3(0, -1, 0), 90);
	      break;
	    case Player::RIGHT:
	      this->rotate(glm::vec3(0, -1, 0), 270);
	      break;
	    }
	  this->_dir = Player::UP;    
	  this->translate(glm::vec3(0, 1, 0) * static_cast<float>(c.getElapsed()) * this->speed);
	}
      if (i.getKey(SDLK_d))
	{
	  double	x = round(this->_position.x + 0.5);
	  double	y = round(this->_position.y);

	  for (double i = 0; i < list.size(); ++i)
	    {
	      if (x == round(list[i]->getPos().x) && y == round(list[i]->getPos().y) && this->_position.z == list[i]->getPos().z)
		return (true);
	    }
	  for (double i = 0; i < wall.size(); ++i)
	    {
	      if (x == round(wall[i]->getPos().x) && y == round(wall[i]->getPos().y) && this->_position.z == wall[i]->getPos().z)
		return (true);
	    }
	  for (double i = 0; i < listBonus.size(); i++)
	    if (x == round(listBonus[i]->getPos().x) && y == round(listBonus[i]->getPos().y))
	      this->pickUpBonus(listBonus, i);
	  switch (this->_dir)
	    {
	    case Player::UP:
	      this->rotate(glm::vec3(0, -1, 0), 90);
	      break;
	    case Player::LEFT:
	      this->rotate(glm::vec3(0, -1, 0), 180);
	      break;
	    case Player::DOWN:
	      this->rotate(glm::vec3(0, -1, 0), 270);
	      break;
	    }
	  this->_dir = Player::RIGHT;    
	  this->translate(glm::vec3(1, 0, 0) * static_cast<float>(c.getElapsed()) * this->speed);
	}
      if (i.getKey(SDLK_q))
	{
	  double	x = round(this->_position.x - 0.5);
	  double	y = round(this->_position.y);

	  for (double i = 0; i < list.size(); ++i)
	    {
	      if (x == round(list[i]->getPos().x) && y == round(list[i]->getPos().y) && this->_position.z == list[i]->getPos().z)
		return (true);
	    }
	  for (double i = 0; i < wall.size(); ++i)
	    {
	      if (x == round(wall[i]->getPos().x) && y == round(wall[i]->getPos().y) && this->_position.z == wall[i]->getPos().z)
		return (true);
	    }
	  for (double i = 0; i < listBonus.size(); i++)
	    if (x == round(listBonus[i]->getPos().x) && y == round(listBonus[i]->getPos().y))
	      this->pickUpBonus(listBonus, i);
	  switch (this->_dir)
	    {
	    case Player::RIGHT:
	      this->rotate(glm::vec3(0, -1, 0), 180);
	      break;
	    case Player::UP:
	      this->rotate(glm::vec3(0, -1, 0), 270);
	      break;
	    case Player::DOWN:
	      this->rotate(glm::vec3(0, -1, 0), 90);
	      break;
	    }
	  this->_dir = Player::LEFT;
	  this->translate(glm::vec3(-1, 0, 0) * static_cast<float>(c.getElapsed()) * this->speed);
	}
    }
  transformation = glm::lookAt(glm::vec3(this->_position.x, this->_position.y - 3, 5), glm::vec3(this->_position.x, this->_position.y, this->_position.z), glm::vec3(0, 1, 0));
  s.setUniform("view", transformation);
  return (true);
}

void			Human::pickUpBonus(std::vector<Bonus *> &b, const int i)
{
  int _type = b[i]->getBonusType();

  switch (_type)
    {
    case 1:
      if (this->power < 7)
	this->power++;
      else
	std::cout << "Puissance de feu maximale atteinte." << std::endl;
      break;
    case 2:
      if (this->nbBomb < 5)
	this->nbBomb++;
      else
	std::cout << "Nombre maximum de bombe atteinte." << std::endl;
      break;
    case 3:
      if (this->speed < 15)
	this->speed += 1.0;
      else
	std::cout << "Vitesse de deplacement maximale atteinte." << std::endl;
      break;
    default:
      break;
    }
  if (i < b.size())
    {
      b[i]->translate(glm::vec3(-10, -10, 100));
      b[i]->setPos(glm::vec3(-10, -10, 100));
    }
}
