//
// Wall.hpp for  in /home/vancom_l/rendu/CPP/hannot_bomberman/cpp_bomberman/Includes
// 
// Made by Lucas Vancompernolle
// Login   <vancom_l@epitech.net>
// 
// Started on  Thu Jun  5 12:37:07 2014 Lucas Vancompernolle
// Last update Tue Jun 10 14:47:34 2014 Lucas Vancompernolle
//

#ifndef		__WALL_HPP__
# define	__WALL_HPP__

# include	"Block.hpp"

class		Wall : public Block
{
private:

public:
  Wall(const glm::vec3 &, glm::vec3 const &);
  virtual	~Wall();
};

#endif		/* __WALL_HPP__ */
