//
// Ia.cpp for Ia in /home/cazheer/Documents/Test/cpp_bomberman
// 
// Made by Thomas Hannot
// Login   <hannot_t@epitech.net>
// 
// Started on  Wed May 28 12:33:54 2014 Thomas Hannot
// Last update Sun Jun 15 23:29:41 2014 Lucas Vancompernolle
//

#include	"Ia.hpp"

Ia::Ia(const glm::vec3 &pos, const std::string &_name) :
  Player(pos, _name, 42), rd(20), bomb(10), research(70)
{
  this->_scale = glm::vec3(0.002, 0.002, 0.002);
  this->_rotation = glm::vec3(90, 0, 0);
  this->asset = "./Assets/human.fbx";
  this->id = 1;
  this->nbBomb = 2;
  this->type = Player::IA;
}

Ia::~Ia()
{
}

bool		Ia::update(gdl::AShader &s, gdl::Clock const &c, gdl::Input &i, const std::vector<Block *> &list, const std::vector<Block *> &wall, std::vector<Bonus *> &bonus)
{
  (void)i;
  (void)c;
  (void)s;
  (void)list;
  (void)wall;
  (void)bonus;
  return (false);
}

bool		Ia::initialize()
{
  if (this->_model.load(this->asset) == false)
    {
      std::cerr << "Cannot load the model : " << this->asset << std::endl;
      return (false);
    }
  TiXmlDocument		doc(IA_CONF);
  if (!doc.LoadFile())
    throw Except("Cannot load the file : Ia.conf");

  TiXmlHandle		hdl(&doc);
  TiXmlElement		*elem = hdl.ChildElement("ia", 0).Element();

  if (!elem || !elem->Attribute("rd", &(this->rd)) ||
      !elem->Attribute("bomb", &(this->bomb)) || !elem->Attribute("search", &(this->research)) ||
      this->rd < 0 || this->bomb < 0 || this->research < 0)
    throw Except("IaXml: Value Error");

  return (true);
}

bool		Ia::update_ia(std::vector<Block *> &list, const std::vector<Block *> &wall,
			      const std::vector<Player *> &human, const std::vector<Player *> &ia,
			      const gdl::Clock &c)
{
  int		r = rand() % (rd + bomb + research);

  if (r < research)
    search(list, wall, human, ia);
  else if (r < research + rd)
    move_rand(list, wall);
  else
    {
      int	c_bomb = 0;

      for (std::size_t it = 0; it < list.size(); it++)
	if (list[it]->getType() == Block::BOMBE && static_cast<Bomb *>(list[it])->getId() == getId())
	  c_bomb++;

      if (c_bomb < nbBomb)
	{
	  Block *bomb = new Bomb(glm::vec3(round(getPosX()), round(getPosY()), getPosH()), glm::vec3(1, 1, 1), getId(), getPower());
	  if (bomb->initialize() == false)
	    throw Except("Error on Bomb initialize");
	  list.push_back(bomb);
	}
    }
  
  switch (_dir)
    {
    case Player::UP:
      if (bump_wall(list, wall))
	translate(glm::vec3(0, 1, 0) * static_cast<float>(c.getElapsed()) * this->speed);
      break;
    case Player::DOWN:
      if (bump_wall(list, wall))
	translate(glm::vec3(0, -1, 0) * static_cast<float>(c.getElapsed()) * this->speed);
      break;
    case Player::LEFT:
      if (bump_wall(list, wall))
	translate(glm::vec3(-1, 0, 0) * static_cast<float>(c.getElapsed()) * this->speed);
      break;
    case Player::RIGHT:
      if (bump_wall(list, wall))
	translate(glm::vec3(1, 0, 0) * static_cast<float>(c.getElapsed()) * this->speed);
      break;
    }
  return true;
}

void		Ia::move_rand(const std::vector<Block *> &list, const std::vector<Block *> &wall)
{
  switch (rand() % 4)
    {
    case 0:
      break;
    case 1:
      _dir = static_cast<Player::e_dir>((static_cast<int>(_dir) + 1) % 4);
      rotate(glm::vec3(0, -1, 0), 90);
      break;
    case 2:
      _dir = static_cast<Player::e_dir>((static_cast<int>(_dir) + 3) % 4);
      rotate(glm::vec3(0, -1, 0), 270);
      break;
    case 3:
      _dir = static_cast<Player::e_dir>((static_cast<int>(_dir) + 2) % 4);
      rotate(glm::vec3(0, -1, 0), 180);
      break;
    }
}

void		Ia::search(const std::vector<Block *> &list, const std::vector<Block *> &wall,
			  const std::vector<Player *> &human, const std::vector<Player *> &ia)
{
  bool		isBomb = false;
  for (std::size_t it = 0; it < list.size(); it++)
    if (list[it]->getType() == Block::BOMBE && list[it]->getPos().x == getPosX())
      {
	isBomb = true;
	_dir = Player::DOWN;
      }
    else if (list[it]->getType() == Block::BOMBE && list[it]->getPos().y == getPosY())
      {
	isBomb = true;
	_dir = Player::RIGHT;
      }

  if (isBomb)
    return ;
  std::size_t	_it = 0;
  double	size = 99999999.999;
  if (human.size() < 0)
    move_rand(list, wall);
  else
    for (std::size_t it = 0; it < human.size(); it++)
      if (human[it]->getPosX() + human[it]->getPosY() - getPosX() - getPosY() < size)
	{
	  _it = it;
	  size = human[it]->getPosX() + human[it]->getPosY() - getPosX() - getPosY();
	}
  rotate(glm::vec3(0, -1, 0), -90 * static_cast<int>(_dir));
  if (human[_it]->getPosX() < getPosX())
    {
      rotate(glm::vec3(0, -1, 0), 90);
      _dir = Player::LEFT;
    }
  else if (human[_it]->getPosX() > getPosX())
    {
      rotate(glm::vec3(0, -1, 0), 270);
      _dir = Player::RIGHT;
    }

  if (human[_it]->getPosX() == getPosX() && human[_it]->getPosY() < getPosY())
    {
      rotate(glm::vec3(0, -1, 0), 180);
      _dir = Player::DOWN;
    }
  else if (human[_it]->getPosX() == getPosX())
    _dir = Player::UP;
}

bool		Ia::bump_wall(const std::vector<Block *> &list, const std::vector<Block *> &wall)
{
  for (std::size_t it = 0; it < list.size(); it++)
    switch (_dir)
      {
      case Player::LEFT:
	if (ABS(list[it]->getPos().x - getPosX() - 1) < 0.5 && ABS(list[it]->getPos().y - getPosY()) < 0.5)
	  return false;
	break;
      case Player::RIGHT:
	if (ABS(list[it]->getPos().x - getPosX() + 1) < 0.5 && ABS(list[it]->getPos().y - getPosY()) < 0.5)
	  return false;
	break;
      case Player::DOWN:
	if (ABS(list[it]->getPos().x - getPosX()) < 0.5 && ABS(list[it]->getPos().y - getPosY() - 1) < 0.5)
	  return false;
	break;
      case Player::UP:
	if (ABS(list[it]->getPos().x - getPosX()) < 0.5 && ABS(list[it]->getPos().y - getPosY() + 1) < 0.5)
	  return false;	
	break;
      }
  for (std::size_t it = 0; it < wall.size(); it++)
    switch (_dir)
      {
      case Player::LEFT:
	if (ABS(wall[it]->getPos().x - getPosX() - 1) < 0.5 && ABS(wall[it]->getPos().y - getPosY()) < 0.5)
	  return false;
	break;
      case Player::RIGHT:
	if (ABS(wall[it]->getPos().x - getPosX() + 1) < 0.5 && ABS(wall[it]->getPos().y - getPosY()) < 0.5)
	  return false;
	break;
      case Player::DOWN:
	if (ABS(wall[it]->getPos().x - getPosX()) < 0.5 && ABS(wall[it]->getPos().y - getPosY() - 1) < 0.5)
	  return false;
	break;
      case Player::UP:
	if (ABS(wall[it]->getPos().x - getPosX()) < 0.5 && ABS(wall[it]->getPos().y - getPosY() + 1) < 0.5)
	  return false;	
	break;
      }
  return true;
}
