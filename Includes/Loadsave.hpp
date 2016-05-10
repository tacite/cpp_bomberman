#ifndef		LOADSAVE_HPP
# define	LOADSAVE_HPP

# include	"GameEngine.hpp"

class		Loadsave
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
  
  Loadsave();
  ~Loadsave();
  
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