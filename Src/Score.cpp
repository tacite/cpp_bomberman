//
// Score.cpp for bomber in /home/dupont-j/cpp_bomberman/Src
// 
// Made by Jean-Antoine Dupont
// Login   <dupont_j@epitech.eu>
// 
// Started on  Wed Jun 11 15:17:45 2014 Jean-Antoine Dupont
// Last update Wed Jun 11 18:04:48 2014 Jean-Antoine Dupont
//

#include			"Score.hpp"

/*
**	Constructor / Deconstructor
*/

Score::Score()
{
  this->list.clear();
  this->pos = BACK;
}

Score::~Score()
{
  this->list.clear();
}

void				Score::reset()
{
  this->list.clear();
}

bool				Score::update(gdl::Input &input)
{
  if (pos != BACK && input.getKey(SDLK_LEFT, true))
    this->pos = static_cast<e_score>(static_cast<int>(pos - 1));
  else if (pos != RESET && input.getKey(SDLK_RIGHT, true))
    this->pos = static_cast<e_score>(static_cast<int>(pos + 1));
  if (input.getKey(SDLK_RETURN))
    return (false);
  return (true);
}

void				Score::draw() const
{
}

void				Score::readFile()
{
  std::ifstream			file(FILE);
  std::string			str;
  char				c;

  str.clear();
  if (file)
    {
      while (file.get(c))
	if (c != '\n')
	  str += c;
	else
	  {
	    if (str != "")
	      this->putScore(str);
	    str.clear();
	  }
      if (str != "")
	this->putScore(str);
      file.close();
    }
}

void				Score::writeFile()
{
  int				size = 0;
  t_score			score;
  std::fstream			fs;
  std::list<t_score>::iterator	it = this->list.begin();

  fs.open(FILE, std::fstream::out | std::fstream::trunc);
  while (it != this->list.end() && size <= NB_SCORE)
    {
      score = *it;
      fs << score.name << ":" << score.score << std::endl;
      it++;
      size++;
    }
  fs.close();
}

void				Score::addScore(const t_score &add)
{
  t_score			tmp;
  std::list<t_score>::iterator	it = this->list.begin();

  while (it != this->list.end())
    {
      tmp = *it;
      if (add.score > tmp.score)
	break;
      it++;
    }
  if (it != this->list.end())
    this->list.insert(it, add);
  else
    this->list.push_back(add);
}

void				Score::putScore(const std::string &str)
{
  std::string			name;
  std::string			score;
  t_score			add;
  unsigned	int		i = 0;

  name.clear();
  score.clear();
  while (str[i] != ':')
    name += str[i++];
  i++;
  while (str[i])
    score += str[i++];
  if (this->checkName(name) == true && this->checkScore(score) == true)
    {
      add.name = name;
      add.score = convert<unsigned int>(score);
      this->addScore(add);
    }
}

bool				Score::checkName(const std::string &name) const
{
  size_t			i = 0;

  while (name[i] && (name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z'))
    i++;
  if (i < 1 || i != name.size())
    {
      std::cout << "Error: Score file is corrupted" << std::endl;
      return (false);
    }
  return (true);
}

bool				Score::checkScore(const std::string &score) const
{
  size_t			i = 0;

  while (score[i] && (score[i] >= '0' && score[i] <= '9'))
    i++;
  if (i < 1 || i != score.size())
    {
      std::cout << "Error: Score file is corrupted" << std::endl;
      return (false);
    }
  return (true);
}

const	std::list<t_score>	&Score::getList() const
{
  return (this->list);
}

const	e_score			&Score::getPos() const
{
  return (this->pos);
}
