//
// Load.hpp for bomber in /home/dupont-j/Perso/cpp_bomberman
// 
// Made by Jean-Antoine Dupont
// Login   <dupont_j@epitech.eu>
// 
// Started on  Fri May 30 15:22:26 2014 Jean-Antoine Dupont
// Last update Sat Jun 14 16:28:46 2014 Jean-Antoine Dupont
//

#ifndef			__LOAD_HPP__
# define		__LOAD_HPP__

# include 		<cstdlib>
# include		"Bomberman.hpp"
# include		"Human.hpp"
# include		"Bomb.hpp"
# include		"Box.hpp"
# include		"Wall.hpp"
//# include		"Bonus.hpp"
# include		"Ia.hpp"
# include		"Xml.hpp"

# define		DIR	"./Save/"

class			Load
{
public:
  Load();
  ~Load();

  void			parsing(const std::string & name = "./Save/default.xml", bool defName = true);

  const std::vector<Player*>	&getPlayer() const;
  const std::vector<Block*>	&getBlock() const;
  const std::vector<Player*>	&getIa() const;
  int				getMapX() const;
  int				getMapY() const;

private:
  void				parsPlayer(TiXmlHandle &);
  void				parsBlock(TiXmlHandle &);
  void				parsBomb(TiXmlHandle &);
  void				parsBonus(TiXmlHandle &);

  void				createPlayer(TiXmlElement *);
  void				createBlock(TiXmlElement *);
  void				createBomb(TiXmlElement *);
  void				createBonus(TiXmlElement *);

  bool				checkPos(const double, const double) const;
  bool				checkId(const int) const;
  bool				checkBomb(const double, const double, const int) const;

  std::vector<Player*>		listPlayer;
  std::vector<Player*>		listIa;
  std::vector<Block*>		listBlock;
  int				mapX;
  int				mapY;
};

#endif			/* __LOAD_HPP__ */
