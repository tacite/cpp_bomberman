//
// Box.hpp for  in /home/vancom_l/rendu/CPP/hannot_bomberman/cpp_bomberman
// 
// Made by Lucas Vancompernolle
// Login   <vancom_l@epitech.net>
// 
// Started on  Thu Jun  5 13:49:44 2014 Lucas Vancompernolle
// Last update Tue Jun 10 14:40:00 2014 Lucas Vancompernolle
//

#ifndef		__BOX_HPP__
# define	__BOX_HPP__

# include	"Block.hpp"

class		Box : public Block
{
private:

public:
  Box(const glm::vec3 &, glm::vec3 const &);
  virtual	~Box();
};

#endif		/* __BOX_HPP__ */
