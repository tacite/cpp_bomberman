//
// Menu.hpp for bomber in /home/dupont-j/Perso/cpp_bomberman
// 
// Made by Jean-Antoine Dupont
// Login   <dupont_j@epitech.eu>
// 
// Started on  Tue May 27 15:06:13 2014 Jean-Antoine Dupont
// Last update Thu Jun 12 13:13:14 2014 Lucas Vancompernolle
//

#ifndef		__MENUSTART_HPP__
# define	__MENUSTART_HPP__

# include	"GameEngine.hpp"

# define	PICT_MENU	"./Assets/menu.tga"
# define	PICT_CURSOR	"./Assets/cursor.tga"

class		MenuStart
{
public:
  enum		e_pos
    {
      NEW_GAME,
      LOAD,
      HIGHSCORE,
      OPTIONS,
      QUIT
    };

  MenuStart();
  ~MenuStart();

  bool		initialize();
  bool		update(gdl::Input &);
  void		draw(gdl::SdlContext &, gdl::BasicShader &);

  e_pos		getMode() const;

private:
  e_pos		pos;
  gdl::Geometry	_geometry;
  gdl::Texture	_texture;
};

#endif	/*	__MENUSTART_HPP__	*/
