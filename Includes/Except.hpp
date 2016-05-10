//
// Except.hpp for Except in /home/cazheer/Documents/ProgElem/Projet/trade
// 
// Made by Thomas Hannot
// Login   <hannot_t@epitech.net>
// 
// Started on  Wed Apr 30 13:41:38 2014 Thomas Hannot
// Last update Wed Apr 30 13:41:40 2014 Thomas Hannot
//

#ifndef			__EXCEPT_HPP__
# define		__EXCEPT_HPP__

# include		<exception>
# include		<sstream>
# include		<cstring>
# include		<string>

class			Except : public std::exception
{
private:
  std::string		str;

public:
  Except(const std::string & s) throw() : str(s) {}
  virtual ~Except() throw() {}

  virtual const char *	what() const throw()
  {
    return (str.c_str());
  }
};

template<typename T>
const std::string &	to_string(const T & n)
{
  std::ostringstream	s;

  s << n;
  return (s.str());
}

template<typename T>
T			convert(const std::string & str)
{
  std::istringstream	o(str);
  T			n;

  o >> n;
  return (n);
}

#endif			/* __EXCEPT_HPP__ */
