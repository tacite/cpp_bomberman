/*
** SkyBox.cpp for  in /home/roledg/CURRENT/cpp_bomberman
** 
** Made by role-d_g
** Login   <roledg@epitech.net>
** 
** Started on  Sat Jun 14 00:20:30 2014 role-d_g
// Last update Sat Jun 14 15:10:14 2014 Lucas Vancompernolle
*/

#include	"SkyBox.hpp"

SkyBox::SkyBox(const glm::vec3  &p, const glm::vec3 &s) : Block(p, s)
{
  this->asset = "./Assets/sky.tga";
  this->type = Block::SKYBOX;
}

SkyBox::~SkyBox()
{

}
