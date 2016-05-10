//
// AnimBox.cpp for  in /home/vancom_l/rendu/CPP/cpp_bomberman/Src
// 
// Made by Lucas Vancompernolle
// Login   <vancom_l@epitech.net>
// 
// Started on  Fri Jun 13 17:41:44 2014 Lucas Vancompernolle
// Last update Fri Jun 13 17:44:12 2014 Lucas Vancompernolle
//

#include "AnimBox.hpp"

AnimBox::AnimBox(const glm::vec3 &pos, const glm::vec3 &sc) : Block(pos, sc)
{
  this->asset = "./Assets/Bombermanrot.tga";
  this->type = Block::SKYBOX;
}

AnimBox::~AnimBox()
{
}
