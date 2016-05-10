//
// Floor.cpp for  in /home/vancom_l/rendu/CPP/cpp_bomberman/Src
// 
// Made by Lucas Vancompernolle
// Login   <vancom_l@epitech.net>
// 
// Started on  Fri Jun 13 13:17:30 2014 Lucas Vancompernolle
// Last update Fri Jun 13 13:19:04 2014 Lucas Vancompernolle
//

#include "Floor.hpp"

Floor::Floor(const glm::vec3 &p, const glm::vec3 &s) : Block(p, s)
{
  this->asset = "./Assets/floor.tga";
  this->type = Block::FLOOR;
}

Floor::~Floor()
{
}
