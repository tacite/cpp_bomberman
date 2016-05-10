//
// Floor.hpp for  in /home/vancom_l/rendu/CPP/cpp_bomberman/Includes
// 
// Made by Lucas Vancompernolle
// Login   <vancom_l@epitech.net>
// 
// Started on  Fri Jun 13 13:19:16 2014 Lucas Vancompernolle
// Last update Fri Jun 13 13:25:06 2014 Lucas Vancompernolle
//

#ifndef FLOOR_HPP__
#define FLOOR_HPP__

#include "Block.hpp"

class Floor : public Block
{
public:
  Floor(const glm::vec3 &, const glm::vec3 &);
  virtual ~Floor();
};

#endif
