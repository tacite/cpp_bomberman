//
// Fire.cpp for  in /home/vancom_l/rendu/CPP/hannot_bomberman/cpp_bomberman
// 
// Made by Lucas Vancompernolle
// Login   <vancom_l@epitech.net>
// 
// Started on  Tue Jun 10 13:34:34 2014 Lucas Vancompernolle
// Last update Tue Jun 10 13:34:39 2014 Lucas Vancompernolle
//

#include "Fire.hpp"

Fire::Fire(const glm::vec3 &pos, const glm::vec3 &sc) : Block(pos, sc)
{
  this->asset = "./Assets/fire.tga";
  this->type = Block::FIRE;
}

Fire::~Fire()
{
}

