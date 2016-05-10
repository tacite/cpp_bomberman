//
// Bomb_new.cpp for  in /home/vancom_l/rendu/CPP/hannot_bomberman/cpp_bomberman/Src
// 
// Made by Lucas Vancompernolle
// Login   <vancom_l@epitech.net>
// 
// Started on  Thu Jun  5 12:55:02 2014 Lucas Vancompernolle
// Last update Sun Jun 15 23:12:52 2014 Lucas Vancompernolle
//

#include		"Bomb.hpp"
#include		"Fire.hpp"

Bomb::Bomb(const glm::vec3 &pos, glm::vec3 const &sc, const int idP, const int p) :
  Block(pos, sc)
{
  this->asset = "./Assets/bomb.tga";
  this->type = Block::BOMBE;
  this->idPlayer = idP;
  this->power = p;
  this->destruction = 0.0;
  this->_x_h = 42000.0;
  this->_x_l = -42000.0;
  this->_y_r = 42000.0;
  this->_y_l = -42000.0;
  this->listFire.clear();
}

Bomb::~Bomb()
{
}

void			Bomb::setStart(const double t)
{
  this->start += t;
}

bool			Bomb::update(gdl::Clock &c)
{
  this->start = 0.0;
  this->destruction += c.getElapsed();
  if (this->destruction > 2)
    {
      this->destruction = 0.0;
      return (true);
    }
  return (false);
}

bool			Bomb::check_wall_y(const size_t dir, const double x, const double y, const std::vector<Block *> &b, std::vector<Bonus *> &listBonus)
{
  int			collision;

  collision = 0;
  if (dir == 0)
    {
      for (size_t i = 0; i < b.size(); ++i)
	{
	  if (y == b[i]->getPos().y && x == b[i]->getPos().x && b[i]->getPos().z == this->_position.z)
	    {
	      if (b[i]->getType() == Block::DESTRUCTIBLE && this->_x_h == 42000.0)
		{
		  this->spawnBonus(b[i]->getPos(), listBonus);
		  b[i]->translate(glm::vec3(-10, -10, 100));
		  b[i]->setPos(glm::vec3(-10, -10, 100));
		}
	      collision++;
	      this->_x_h = x;
	    }
	  if (y > b[i]->getPos().y && this->_x_h == x)
	    collision++;
	}
    }
  else
    {
      for (size_t i = 0; i < b.size(); ++i)
	{
	  if (y == b[i]->getPos().y && x == b[i]->getPos().x && b[i]->getPos().z == this->_position.z)
	    {
	      if (b[i]->getType() == Block::DESTRUCTIBLE && this->_x_l == -42000.0)
		{
		  this->spawnBonus(b[i]->getPos(), listBonus);
		  b[i]->translate(glm::vec3(-10, -10, 100));
		  b[i]->setPos(glm::vec3(-10, -10, 100));
		}
	      collision++;
	      this->_x_l = x;
	    }
	    if (y < b[i]->getPos().y && this->_x_l == x)
	      collision++;
	}      
    }
  if (collision > 0)
    return (false);
  return (true);
}

bool			Bomb::check_wall_x(const size_t dir, const double x, const double y, const std::vector<Block *> &b, std::vector<Bonus *> &listBonus)
{
  int			collision;

  collision = 0;
  if (dir == 0)
    {
      for (size_t i = 0; i < b.size(); ++i)
	{
	  if (y == b[i]->getPos().y && x == b[i]->getPos().x  && b[i]->getPos().z == this->_position.z)
	    {
	      if (b[i]->getType() == Block::DESTRUCTIBLE && this->_y_r == 42000.0)
		{
		  this->spawnBonus(b[i]->getPos(), listBonus);
		  b[i]->translate(glm::vec3(-10, -10, 100));
		  b[i]->setPos(glm::vec3(-10, -10, 100));
		}
	      collision++;
	      this->_y_r = y;
	    }
	  if (x > b[i]->getPos().x && this->_y_r == y)
	    collision++;
	}
    }
  else
    {
      for (size_t i = 0; i < b.size(); ++i)
	{
	  if (y == b[i]->getPos().y && x == b[i]->getPos().x && b[i]->getPos().z == this->_position.z)
	    {
	      if (b[i]->getType() == Block::DESTRUCTIBLE && this->_y_l == -42000.0)
		{
		  this->spawnBonus(b[i]->getPos(), listBonus);
		  b[i]->translate(glm::vec3(-10, -10, 100));
		  b[i]->setPos(glm::vec3(-10, -10, 100));
		}
	      collision++;
	      this->_y_l = y;
	    }
	  if (x < b[i]->getPos().y && this->_y_l == y)
	    collision++;
	}      
    }
  if (collision > 0)
    return (false);
  return (true);
}

void			Bomb::destroy(const std::vector<Block *> &b, const std::vector<Block *> &w, std::vector<Bonus *> &lb)
{
  std::vector<Fire *>	tmp;
  Fire			*f = new Fire(this->_position, glm::vec3(1, 1, 1));
  
  tmp.clear();
  f->initialize();
  tmp.push_back(f);
  for (int i = 1; i <= this->power; ++i)
    {
      if (this->check_wall_y(0, this->_position.x, this->_position.y + i, b, lb) == true && this->check_wall_y(0, this->_position.x, this->_position.y + i, w, lb) == true)
	{
	  Fire *ff = new Fire(glm::vec3(this->_position.x, this->_position.y + i, 0), glm::vec3(1, 1, 1));
	  ff->initialize();
	  tmp.push_back(ff);
	}
      if (this->check_wall_y(1, this->_position.x, this->_position.y - i, b, lb) == true && this->check_wall_y(1, this->_position.x, this->_position.y - i, w, lb) == true)
	{
	  Fire *ff = new Fire(glm::vec3(this->_position.x, this->_position.y - i, 0), glm::vec3(1, 1, 1));
	  ff->initialize();
	  tmp.push_back(ff);
	}
      if (this->check_wall_x(0, this->_position.x + i, this->_position.y, b, lb) == true && this->check_wall_x(0, this->_position.x + i, this->_position.y, w, lb) == true)
	{
	  Fire *ff = new Fire(glm::vec3(this->_position.x + i, this->_position.y, 0), glm::vec3(1, 1, 1));
	  ff->initialize();
	  tmp.push_back(ff);
	}
      if (this->check_wall_x(1, this->_position.x - i, this->_position.y, b, lb) == true && this->check_wall_x(1, this->_position.x - i, this->_position.y, w, lb) == true)
	{
	  Fire *ff = new Fire(glm::vec3(this->_position.x - i, this->_position.y, 0), glm::vec3(1, 1, 1));
	  ff->initialize();
	  tmp.push_back(ff);
	}
    }
  this->listFire = tmp;
}

std::vector<Fire *>	Bomb::getFire() const
{
  return (this->listFire);
}

double			Bomb::getStart() const
{
  return (this->start);
}

int			Bomb::getId() const
{
  return this->idPlayer;
}

int			Bomb::getPower() const
{
  return this->power;
}

void			Bomb::spawnBonus(const glm::vec3 &pos, std::vector<Bonus *> &listBonus)
{
  int _rand = rand() % 4 + 1;

  if (_rand >= 3)
    {

      Bonus *b = new Bonus(glm::vec3(pos.x, pos.y, 0.125) , glm::vec3(0.75, 0.75, 0.75));
      if (b->initialize() == false)
	{
	  throw Except("Can not initialize bonus");
	}
      listBonus.push_back(b);
    }
}
