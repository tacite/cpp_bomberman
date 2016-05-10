//
// Wall.cpp for  in /home/vancom_l/rendu/CPP/hannot_bomberman/cpp_bomberman/Src
// 
// Made by Lucas Vancompernolle
// Login   <vancom_l@epitech.net>
// 
// Started on  Thu Jun  5 12:36:43 2014 Lucas Vancompernolle
// Last update Tue Jun 10 14:46:22 2014 Lucas Vancompernolle
//

#include	"Wall.hpp"

Wall::Wall(const glm::vec3 &pos, glm::vec3 const &sc) :
  Block(pos, sc)
{
  this->asset = "./Assets/wall.tga";
  this->type = Block::INDESTRUCTIBLE;
}

Wall::~Wall()
{
}
