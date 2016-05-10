#ifndef		LOADGAME_HPP
# define	LOADGAME_HPP

# include	"GameEngine.hpp"

class		Loadgame
{
public:
  enum		position
  {
    FIRST = 0,
    SECOND,
    THIRD,
    FOURTH,
    QUIT,
  };
  
  Loadgame();
  ~Loadgame();
  
  bool		initialize();
  bool		update(gdl::Input &);
  void		draw(gdl::SdlContext &, gdl::BasicShader &);
  
  position	getMode() const;
  
private:
  position	_pos;
  gdl::Geometry	_geometry;
  gdl::Texture	_texture;
};

#endif