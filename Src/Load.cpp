/*
** Load.cpp for  in /home/roledg/CURRENT/cpp_bomberman
** 
** Made by role-d_g
** Login   <roledg@epitech.net>
** 
** Started on  Sun Jun 15 23:42:49 2014 role-d_g
** Last update Sun Jun 15 23:42:51 2014 role-d_g
*/

#include	"Load.hpp"

Load::Load()
{
  listPlayer.clear();
  listIa.clear();
  listBlock.clear();
  mapX = 0;
  mapY = 0;
}

Load::~Load()
{
  listPlayer.clear();
  listIa.clear();
  listBlock.clear();
}

const std::vector<Player*>	&Load::getPlayer() const
{
  return listPlayer;
}

const std::vector<Player*>	&Load::getIa() const
{
  return listIa;
}

const std::vector<Block*>	&Load::getBlock() const
{
  return listBlock;
}

int			Load::getMapX() const
{
  return mapX;
}

int			Load::getMapY() const
{
  return mapY;
}

void			Load::parsing(const std::string & name, bool defName)
{
  std::string		new_name = name;
  
  if (defName)
    new_name = DIR + name + ".xml";

  TiXmlDocument		doc(new_name.c_str());

  if (!doc.LoadFile())
    throw Except("Can not load the file : " + new_name);

  TiXmlHandle		hdl(&doc);

  TiXmlElement		*elem = hdl.ChildElement(MAP, 0).Element();

  if (!elem || !elem->Attribute(SIZEX, &(this->mapX)) || !elem->Attribute(SIZEY, &(this->mapY)) ||
      (mapX = atoi(elem->Attribute(SIZEX, &(this->mapX)))) < MIN_SIZE ||
      (mapY = atoi(elem->Attribute(SIZEY, &(this->mapY)))) < MIN_SIZE)
    throw Except("ParsingXml: Error to initialize the map");

  parsPlayer(hdl);
  parsBlock(hdl);
  parsBomb(hdl);
}

void			Load::parsPlayer(TiXmlHandle & hdl)
{
  TiXmlElement		*elem = hdl.ChildElement(MAP, 0).ChildElement(PLAYER, 0).Element();

  while (elem)
    {
      if (!elem->Attribute(IDP) || !elem->Attribute(POSX) || !elem->Attribute(POSY) ||
	  !elem->Attribute(TYPE) || !elem->Attribute(NAME) || !elem->Attribute(NB_BOMB) ||
	  !elem->Attribute(PO_BOMB) || !elem->Attribute(SPEED) || !elem->Attribute(SCORE))
	throw Except("ParsingXml: Missing element while loading player");
      else if (atoi(elem->Attribute(POSX)) < 0 || atoi(elem->Attribute(POSX)) > mapX ||
	       atoi(elem->Attribute(POSY)) < 0 || atoi(elem->Attribute(POSY)) > mapY)
	throw Except("ParsingXml: Player outside of the map");
      else
	createPlayer(elem);
      elem = elem->NextSiblingElement(PLAYER);
    }

  if (listPlayer.size() < 1)
    throw Except("ParsingXml: Need at least 2 human player");
}

void			Load::createPlayer(TiXmlElement *elem)
{
  Player		*player;
  int 			i;
  Player::e_type	type = static_cast<Player::e_type>(atoi(elem->Attribute(TYPE, &i)));


  if (type == Player::HUMAN)
    player = new Human(glm::vec3(atof(elem->Attribute(POSX, &i)), atof(elem->Attribute(POSY, &i)), 0), elem->Attribute(NAME, &i), 0);
  else if (type == Player::IA)
    player = new Ia(glm::vec3(atof(elem->Attribute(POSX, &i)), atof(elem->Attribute(POSY, &i)), 0), elem->Attribute(NAME, &i));
  else
    throw Except("ParsingXml: Unknow type of player");

  int			id = atoi(elem->Attribute(IDP, &i));

  player->setId(id);
  player->setNbBomb(atoi(elem->Attribute(NB_BOMB, &i)));
  player->setPower(atoi(elem->Attribute(PO_BOMB, &i)));
  player->setSpeed(atof(elem->Attribute(SPEED, &i)));
  player->setScore(atoi(elem->Attribute(SCORE, &i)));

  if (player->initialize() == false)
    throw("Player fail");

  if (!checkPos(player->getPosX(), player->getPosY()) || !checkId(player->getId()) ||
      player->getSpeed() <= 1.0 || player->getSpeed() > 20.0)
    throw Except("ParsingXml: Wrong data to player");

  if (type == Player::HUMAN)
    listPlayer.push_back(player);
  else
    listIa.push_back(player);
}

void			Load::parsBlock(TiXmlHandle & hdl)
{
  TiXmlElement		*elem = hdl.ChildElement(MAP, 0).ChildElement(BLOCK, 0).Element();
  int			i;

  while (elem)
    {
      if (!elem->Attribute(POSX, &i) || !elem->Attribute(POSY, &i) || !elem->Attribute(TYPE, &i))
	throw Except("ParsingXml: Missing element while loading block");
      else if (atoi(elem->Attribute(POSX, &i)) < 0 || i > mapX ||
	       atoi(elem->Attribute(POSY, &i)) < 0 || i > mapY)
	throw Except("ParsingXml: Block outside of the map");
      else
	createBlock(elem);
      elem = elem->NextSiblingElement(BLOCK);
    }
}

void			Load::createBlock(TiXmlElement *elem)
{
  Block		*block;
  int 		i;
  Block::e_type	type = static_cast<Block::e_type>(atoi(elem->Attribute(TYPE, &i)));

  if (type == Block::INDESTRUCTIBLE)
    block = new Wall(glm::vec3(atof(elem->Attribute(POSX, &i)), atof(elem->Attribute(POSY, &i)), 0), glm::vec3(1, 1, 1));
  else if (type == Block::DESTRUCTIBLE)
    block = new Box(glm::vec3(atof(elem->Attribute(POSX, &i)), atof(elem->Attribute(POSY, &i)), 0), glm::vec3(1, 1, 1));
  else
    throw Except("ParsingXml: Unknow type of block");

  if (block->initialize() == false)
    throw("Cannot initialize block");

  if (!checkPos(block->getPos().x, block->getPos().y))
    throw Except("ParsingXml: Wrong data to block");

  listBlock.push_back(block);
}

void			Load::parsBomb(TiXmlHandle & hdl)
{
  TiXmlElement		*elem = hdl.ChildElement(MAP, 0).ChildElement(BOMB, 0).Element();
  int 			i;
  
  while (elem)
    {
      if (!elem->Attribute(IDP, &i) || !elem->Attribute(POSX, &i) ||
	  !elem->Attribute(POSY, &i) || !elem->Attribute(TIME, &i) || !elem->Attribute(POWER, &i))
	throw Except("ParsingXml: Missing element while loading bomb");
      else if (atoi(elem->Attribute(POSX, &i)) < 0 || atoi(elem->Attribute(POSX, &i)) > mapX ||
	       atoi(elem->Attribute(POSY, &i)) < 0 || atoi(elem->Attribute(POSY, &i)) > mapY)
	throw Except("ParsingXml: Bomb outside of the map");
      else
	createBomb(elem);
      elem = elem->NextSiblingElement(BOMB);
    }
}

void			Load::createBomb(TiXmlElement *elem)
{
  Block			*bomb;
  int 			i;
  bomb = new Bomb(glm::vec3(atof(elem->Attribute(POSX, &i)), atof(elem->Attribute(POSY, &i)),
			    atof(elem->Attribute(TIME, &i))), glm::vec3(1, 1, 1),
		  atoi(elem->Attribute(IDP, &i)), atoi(elem->Attribute(POWER, &i)));

  if (!checkBomb(bomb->getPos().x, bomb->getPos().y, static_cast<Bomb *>(bomb)->getId()))
    throw Except("ParsingXml: Bomb on wrong position");
  listBlock.push_back(bomb);
}

bool			Load::checkPos(const double _x, const double _y) const
{
  for (std::size_t it = 0; it < listPlayer.size(); it++)
    if (listPlayer[it]->getPosX() == _x && listPlayer[it]->getPosY() == _y)
      return false;
  for (std::size_t it = 0; it < listBlock.size(); it++)
    if (listBlock[it]->getPos().x == _x && listBlock[it]->getPos().y == _y)
      return false;
  return true;
}

bool			Load::checkId(const int _id) const
{
  for (std::size_t it = 0; it < listPlayer.size(); it++)
    if (listPlayer[it]->getId() == _id)
      return false;
  return true;
}

bool			Load::checkBomb(const double _x, const double _y, const int _id) const
{
  std::size_t		it;

  for (it = 0; it < listPlayer.size() && listPlayer[it]->getId() != _id; it++);
  if (it == listPlayer.size())
    throw Except("ParsingXml: data error [id] for bomb");
  for (it = 0; it < listPlayer.size(); it++)
    if (listPlayer[it]->getPosX() == _x && listPlayer[it]->getPosY() == _y && listPlayer[it]->getId() != _id)
      return false;
  for (it = 0; it < listBlock.size(); it++)
    if (listBlock[it]->getPos().x == _x && listBlock[it]->getPos().y == _y)
      return false;
  return true;
}
