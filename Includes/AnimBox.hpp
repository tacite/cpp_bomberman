//
// AnimBox.hpp for  in /home/vancom_l/rendu/CPP/cpp_bomberman/Includes
// 
// Made by Lucas Vancompernolle
// Login   <vancom_l@epitech.net>
// 
// Started on  Fri Jun 13 17:44:27 2014 Lucas Vancompernolle
// Last update Fri Jun 13 17:45:20 2014 Lucas Vancompernolle
//

#ifndef ANIMBOX_HPP__
#define ANIMBOX_HPP__

# include "Block.hpp"

class AnimBox : public Block
{
public:
  AnimBox(const glm::vec3 &, const glm::vec3 &);
  ~AnimBox();
};

#endif
