//
// Ia.hpp for Ia in /home/cazheer/Documents/Test/cpp_bomberman
// 
// Made by Thomas Hannot
// Login   <hannot_t@epitech.net>
// 
// Started on  Wed May 28 12:31:23 2014 Thomas Hannot
// Last update Sun Jun 15 23:29:48 2014 Lucas Vancompernolle
//

#ifndef		__IA_HPP__
# define	__IA_HPP__

# include	"Player.hpp"
# include	"Bomb.hpp"
# include	"Xml.hpp"

# define	ABS(x)		((x) < 0 ? (-x) : (x))

# define	IA_CONF		"Ia.conf"

/*
** Classe Ia Player
*/

class		Ia : public Player
{
private:
  int		rd;
  int		bomb;
  int		research;

public:
  Ia(const glm::vec3 &, const std::string &);
  virtual	~Ia();

  virtual bool	initialize();
  virtual bool	update(gdl::AShader &, gdl::Clock const &, gdl::Input &, const std::vector<Block *> &, const std::vector<Block *> &, std::vector<Bonus *> &);

  bool		update_ia(std::vector<Block *> &list, const std::vector<Block *> &wall,
			  const std::vector<Player *> &human, const std::vector<Player *> &ia,
			  const gdl::Clock &c);

private:
  void		move_rand(const std::vector<Block *> &list, const std::vector<Block *> &wall);
  void		search(const std::vector<Block *> &list, const std::vector<Block *> &wall,
		      const std::vector<Player *> &human, const std::vector<Player *> &ia);
  bool		bump_wall(const std::vector<Block *> &list, const std::vector<Block *> &wall);
};

#endif		/* __IA_HPP__ */
