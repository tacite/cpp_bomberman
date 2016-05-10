//
// HighScore.hpp for HighScore in /home/hugo/cpp_bomberman
// 
// Made by Hugo Houyez
// Login   <hugo@epitech.net>
// 
// Started on  Sun Jun 15 18:11:48 2014 Hugo Houyez
// Last update Sun Jun 15 23:20:24 2014 Lucas Vancompernolle
//

#ifndef		HIGHSCORE_HPP
# define	HIGHSCORE_HPP

#include	"GameEngine.hpp"

class		HighScore
{
public:
  HighScore();
  ~HighScore();

public:
   bool	initialize(gdl::AShader & _shader, gdl::SdlContext & _context, gdl::Clock & _clock, gdl::Input & _input);
  bool		play(gdl::AShader & _shader, gdl::SdlContext & _context, gdl::Input & _input);

private:
  gdl::Geometry			_geometry;
  gdl::Texture			_texture;
  glm::mat4			projection;
  glm::mat4			transformation;
};

#endif
