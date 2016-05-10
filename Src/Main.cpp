/*
** main.cpp for  in /home/roledg/cpp_bomberman
** 
** Made by role-d_g
** Login   <roledg@epitech.net>
** 
** Started on  Thu May 15 23:04:06 2014 role-d_g
// Last update Sat Jun 14 15:42:32 2014 Lucas Vancompernolle
*/

#include	"Engine.hpp"

int		main()
{
  try
    {
      Engine	*engine = new Engine;

      srand(time(NULL) + 18);
      engine->initialize();
      engine->play();

      delete engine;
    }
  catch (const std::exception & e)
    {
      std::cerr << "[Bomberman Error] : " << e.what() << std::endl;
      return 1;
    }
  return 0;
}
