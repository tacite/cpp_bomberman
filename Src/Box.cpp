//
// Box.cpp for  in /home/vancom_l/rendu/CPP/hannot_bomberman/cpp_bomberman/Src
// 
// Made by Lucas Vancompernolle
// Login   <vancom_l@epitech.net>
// 
// Started on  Thu Jun  5 13:50:43 2014 Lucas Vancompernolle
// Last update Tue Jun 10 14:40:17 2014 Lucas Vancompernolle
//

#include "Box.hpp"

Box::Box(const glm::vec3 &pos, glm::vec3 const &sc) :
  Block(pos, sc)
{
  this->asset = "./Assets/box.tga";
  this->type = Block::DESTRUCTIBLE;
}

Box::~Box()
{
}
