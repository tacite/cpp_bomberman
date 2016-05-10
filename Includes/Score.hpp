//
// Score.hpp for bomber in /home/dupont-j/cpp_bomberman/Includes
// 
// Made by Jean-Antoine Dupont
// Login   <dupont_j@epitech.eu>
// 
// Started on  Wed Jun 11 15:15:57 2014 Jean-Antoine Dupont
// Last update Wed Jun 11 18:05:44 2014 Jean-Antoine Dupont
//

#ifndef			SCORE_HPP_
# define		SCORE_HPP_

# include			<list>
# include			<fstream>
# include			<iostream>
# include			"GameEngine.hpp"
# define			FILE		".score"
# define			NB_SCORE	(25)

typedef	struct	s_score		t_score;

enum				e_score
  {
    BACK = 0,
    RESET
  };

class				Score
{
public:
  Score();
  ~Score();

  void				reset();
  bool				update(gdl::Input &);
  void				draw() const;

  void				readFile();
  void				writeFile();

  void				addScore(const t_score &);
  void				putScore(const std::string &);

  bool				checkName(const std::string &) const;
  bool				checkScore(const std::string &) const;

  const	std::list<t_score>     	&getList() const;
  const	e_score			&getPos() const;

protected:
  std::list<t_score>		list;
  e_score			pos;
};

struct				s_score
{
  unsigned	int		score;
  std::string			name;
};

#endif	/*		SCORE_HPP_		*/
