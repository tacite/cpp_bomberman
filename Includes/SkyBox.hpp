//
// SkyBox.hpp for SkyBox in /home/hugo/cpp_bomberman/Src
// 
// Made by Hugo Houyez
// Login   <hugo@epitech.net>
// 
// Started on  Tue Jun 10 14:58:36 2014 Hugo Houyez
// Last update Fri Jun 13 13:21:35 2014 Lucas Vancompernolle
//

#ifndef		SKYBOX_HPP__
# define	SKYBOX_HPP__

#include	"Block.hpp"

class		SkyBox : public Block
{
public:
  SkyBox(const glm::vec3 &, const glm::vec3 &);
  virtual ~SkyBox();
};

#endif
