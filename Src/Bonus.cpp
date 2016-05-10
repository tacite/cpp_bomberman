//
// Bonus.cpp for bomber in /home/dupont-j/Perso/cpp_bomberman/Src
// 
// Made by Jean-Antoine Dupont
// Login   <dupont_j@epitech.eu>
// 
// Started on  Wed Jun  4 15:00:44 2014 Jean-Antoine Dupont
// Last update Sat Jun 14 15:42:12 2014 Lucas Vancompernolle
//

#include	"Bonus.hpp"

Bonus::Bonus(const glm::vec3 &p, const glm::vec3 &s) : Block(p, s)
{
  this->type = Block::BONUS;
  this->getRandomBonus();
}

Bonus::~Bonus()
{
}

void Bonus::getRandomBonus()
{
  int _rand = random() % 3 + 1;
  this->bonusType = _rand;
  std::stringstream ss;
  ss << _rand;
  std::string toS = ss.str();
  this->asset = "./Assets/bonus" + toS + ".tga";
}

int Bonus::getBonusType() const
{
  return (this->bonusType);
}
