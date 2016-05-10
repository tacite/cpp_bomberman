/*
** Save.hpp for  in /home/roledg/BON_CPP/cpp_bomberman
** 
** Made by role-d_g
** Login   <roledg@epitech.net>
** 
** Started on  Sun Jun 15 13:37:47 2014 role-d_g
** Last update Sun Jun 15 13:50:19 2014 role-d_g
*/

#ifndef		__SAVE_HPP__
# define	__SAVE_HPP__

# include	"GameEngine.hpp"
# include	"Xml.hpp"
# define	DIR		"./Save/"

class		Save
{
public:
  Save();
  ~Save();

  void		saveFile(const GameEngine *, const std::string & name = "./Save/default.xml");

private:
  void		saveBlock(const GameEngine *, TiXmlElement *);
  void		savePlayer(const GameEngine *, TiXmlElement *);
};

#endif		/* __SAVE_HPP__ */
