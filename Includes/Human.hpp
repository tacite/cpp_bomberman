//
// Human.hpp for Human in /home/cazheer/Documents/Test/cpp_bomberman
// 
// Made by Thomas Hannot
// Login   <hannot_t@epitech.net>
// 
// Started on  Wed May 28 12:31:10 2014 Thomas Hannot
// Last update Sun Jun 15 23:25:22 2014 Lucas Vancompernolle
//

#ifndef		__HUMAN_HPP__
# define	__HUMAN_HPP__

#include "Player.hpp"
#include "Bonus.hpp"

class Human : public Player
{
private:
  void	pickUpBonus(std::vector<Bonus *> &, const int);

public:
  Human(const glm::vec3 &, const std::string &, int number);
  virtual ~Human();
  
  virtual bool update(gdl::AShader &, const gdl::Clock &, gdl::Input &, const std::vector<Block *> &, const std::vector<Block *> &, std::vector<Bonus *> &);
};

#endif
