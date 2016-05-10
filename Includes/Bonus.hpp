//
// Bonus.hpp for bomber in /home/dupont-j/Perso/cpp_bomberman/Includes
// 
// Made by Jean-Antoine Dupont
// Login   <dupont_j@epitech.eu>
// 
// Started on  Wed Jun  4 15:02:00 2014 Jean-Antoine Dupont
// Last update Sat Jun 14 15:33:50 2014 Lucas Vancompernolle
//

#ifndef		__BONUS_HPP__
# define	__BONUS_HPP__

# include	"Block.hpp"
# include	"Except.hpp"

class		Bonus : public Block
{
public:
  Bonus(const glm::vec3 &, const glm::vec3 &);
  virtual ~Bonus();

  int getBonusType() const;

private:
  int bonusType;

  void getRandomBonus();
};

#endif		/* __BONUS_HPP__ */
