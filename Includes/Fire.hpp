//
// Fire.hpp for  in /home/vancom_l/rendu/CPP/hannot_bomberman/cpp_bomberman
// 
// Made by Lucas Vancompernolle
// Login   <vancom_l@epitech.net>
// 
// Started on  Tue Jun 10 13:32:29 2014 Lucas Vancompernolle
// Last update Fri Jun 13 13:21:04 2014 Lucas Vancompernolle
//

#ifndef FIRE_HPP__
#define FIRE_HPP__

#include "Block.hpp"

class Fire : public Block
{
public:
  Fire(const glm::vec3 &, const glm::vec3 &);
  virtual ~Fire();
  
private:
};

#endif
