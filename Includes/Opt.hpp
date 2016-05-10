/*
** Opt.hpp for  in /home/roledg/CURRENT/cpp_bomberman
** 
** Made by role-d_g
** Login   <roledg@epitech.net>
** 
** Started on  Sat Jun 14 18:06:03 2014 role-d_g
** Last update Sat Jun 14 18:06:05 2014 role-d_g
*/

#ifndef		OPT_HPP
# define	OPT_HPP

# include	"GameEngine.hpp"

class		Opt
{
 public:
   enum	e_enum
   {
      SINGLE_NOSOUND = 0,
      MULTI_NOSOUND,
      SINGLE_SOUND,
      MULTI_SOUND
    };

  enum	e_mode
    {
      NBPLAYER = 0,
      SOUND
    };

  Opt();
  ~Opt();

  bool		initialize();
  bool		update(gdl::Input &);
  void		draw(gdl::SdlContext &, gdl::BasicShader &);

  e_enum	getMode() const;

private:
  e_mode	h;
  e_enum	pos;
  gdl::Geometry	_geometry;
  gdl::Texture	_texture;
};

#endif
