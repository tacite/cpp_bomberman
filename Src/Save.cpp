//
// Save.cpp for Save in /home/cazheer/Documents/Test/cpp_bomberman
// 
// Made by Thomas Hannot
// Login   <hannot_t@epitech.net>
// 
// Started on  Wed Jun  4 16:09:55 2014 Thomas Hannot
// Last update Wed Jun  4 16:09:57 2014 Thomas Hannot
//

#include		"Save.hpp"

Save::Save()
{
}

Save::~Save()
{
}

void			Save::saveFile(const GameEngine * engine, const std::string & name)
{
  TiXmlDocument		doc;
  TiXmlDeclaration	*decl = new TiXmlDeclaration("1.0", "utf-8", "");
  doc.LinkEndChild(decl);
  TiXmlElement*		map = new TiXmlElement(MAP);
  map->SetAttribute(SIZEX, engine->getSizeX());
  map->SetAttribute(SIZEY, engine->getSizeY());
  doc.LinkEndChild(map);
  saveBlock(engine, map);
  savePlayer(engine, map);
  doc.SaveFile(DIR + name + ".xml");
}

void			Save::saveBlock(const GameEngine *engine, TiXmlElement *map)
{
  for (size_t i = 0; i < engine->getBlock().size(); i++)
    if (engine->getBlock()[i]->getPos().x > 0 && engine->getBlock()[i]->getPos().y > 0)
      {
	TiXmlElement	*element;
	if (engine->getBlock()[i]->getType() == Block::DESTRUCTIBLE ||
	    engine->getBlock()[i]->getType() == Block::INDESTRUCTIBLE)
	  element = new TiXmlElement(BLOCK);
	else if (engine->getBlock()[i]->getType() == Block::BOMBE)
	  element = new TiXmlElement(BOMB);
	element->SetAttribute(POSX, engine->getBlock()[i]->getPos().x);
	element->SetAttribute(POSY, engine->getBlock()[i]->getPos().y);
	element->SetAttribute(TYPE, engine->getBlock()[i]->getType());
	if (engine->getBlock()[i]->getType() == Block::BOMBE)
	  {
	    element->SetAttribute(IDP, static_cast<Bomb *>(engine->getBlock()[i])->getId());
	    element->SetAttribute(TIME, static_cast<Bomb *>(engine->getBlock()[i])->getStart());
	    element->SetAttribute(PO_BOMB, static_cast<Bomb *>(engine->getBlock()[i])->getPower());
	  }
	map->LinkEndChild(element);
      }
}

void			Save::savePlayer(const GameEngine *engine, TiXmlElement *map)
{
  for (size_t i = 0; i < engine->getPlayer().size(); i++)
    {
      TiXmlElement	*element = new TiXmlElement(PLAYER);
      element->SetAttribute(POSX, engine->getPlayer()[i]->getPosX());
      element->SetAttribute(POSY, engine->getPlayer()[i]->getPosY());
      element->SetAttribute(TYPE, engine->getPlayer()[i]->getType());
      element->SetAttribute(IDP, engine->getPlayer()[i]->getId());
      element->SetAttribute(SPEED, engine->getPlayer()[i]->getSpeed());
      element->SetAttribute(SCORE, engine->getPlayer()[i]->getScore());
      element->SetAttribute(NB_BOMB, engine->getPlayer()[i]->getNbBomb());
      element->SetAttribute(PO_BOMB, engine->getPlayer()[i]->getPower());
      element->SetAttribute(NAME, engine->getPlayer()[i]->getName());
      map->LinkEndChild(element);
    }
  
  for (size_t i = 0; i < engine->getIa().size(); i++)
    {
      TiXmlElement	*element = new TiXmlElement(PLAYER);
      element->SetAttribute(POSX, engine->getIa()[i]->getPosX());
      element->SetAttribute(POSY, engine->getIa()[i]->getPosY());
      element->SetAttribute(TYPE, engine->getIa()[i]->getType());
      element->SetAttribute(IDP, engine->getIa()[i]->getId());
      element->SetAttribute(SPEED, engine->getIa()[i]->getSpeed());
      element->SetAttribute(SCORE, engine->getIa()[i]->getScore());
      element->SetAttribute(NB_BOMB, engine->getIa()[i]->getNbBomb());
      element->SetAttribute(PO_BOMB, engine->getIa()[i]->getPower());
      element->SetAttribute(NAME, engine->getIa()[i]->getName());
      map->LinkEndChild(element);
    }
}