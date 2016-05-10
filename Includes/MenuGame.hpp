/*
** MenuGame.hpp for  in /home/roledg/BON_CPP/cpp_bomberman
** 
** Made by role-d_g
** Login   <roledg@epitech.net>
** 
** Started on  Sun Jun 15 12:26:00 2014 role-d_g
** Last update Sun Jun 15 12:26:01 2014 role-d_g
*/

#ifndef		MENUGAME_HPP_
# define	MENUGAME_HPP_

# include	"GameEngine.hpp"

class		MenuGame
{
public:
  enum		e_pos
    {
      PLAY = 0,
      SAVE,
      BACK,
      QUIT
    };

  MenuGame();
  ~MenuGame();

  bool		initialize();
  bool		update(gdl::Input &);
  void		draw(gdl::SdlContext &, gdl::AShader &);

  e_pos		getMode() const;

private:
   gdl::Geometry	_geometry;
  gdl::Texture		_texture;

protected:
  e_pos		pos;
};

#endif	/*	MENUGAME_HPP_		*/
