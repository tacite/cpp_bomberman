//
// Animation.hpp for Animation in /home/hugo/cpp_bomberman/Src
// 
// Made by Hugo Houyez
// Login   <hugo@epitech.net>
// 
// Started on  Tue Jun 10 14:41:06 2014 Hugo Houyez
// Last update Sun Jun 15 23:09:20 2014 Lucas Vancompernolle
//

#ifndef		ANIMATION_HPP
# define	ANIMATION_HPP

#include	"AnimBox.hpp"
#include	"GameEngine.hpp"

class		Animation
{
  
private:
  Human		*marvin;
  AnimBox	*obj;
  double	pos;
  int		OneD;
  glm::mat4			projection;
  glm::mat4			transformation;
  
public:
  Animation();
  ~Animation();
  
public:
  void		initialize(gdl::AShader & _shader, gdl::SdlContext & _context, gdl::Clock & _clock, gdl::Input & _input);
  bool		play(gdl::AShader & _shader, gdl::SdlContext & _context, gdl::Input & _input);
};

#endif
