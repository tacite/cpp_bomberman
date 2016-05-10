/*
** Animation.cpp for  in /home/roledg/CURRENT/cpp_bomberman
** 
** Made by role-d_g
** Login   <roledg@epitech.net>
** 
** Started on  Sat Jun 14 00:57:26 2014 role-d_g
// Last update Sun Jun 15 23:09:04 2014 Lucas Vancompernolle
*/

#include	"Animation.hpp"

Animation::Animation()
{
  this->pos = -3.0;
  this->OneD = 0;
  this->marvin = new Human(glm::vec3(-3, 1, 1), "JacquieMichel", 0);
  this->obj = new AnimBox(glm::vec3(2, 2, -5), glm::vec3(1.8, 1.3, 0.5));
  this->projection = glm::perspective(60.0f, 800.0f / 600.0f, 0.1f, 100.0f);
  this->transformation  = glm::lookAt(glm::vec3(0, -1, 5), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
}

Animation::~Animation()
{
}

void		Animation::initialize(gdl::AShader & _shader, gdl::SdlContext & _context, gdl::Clock & _clock, gdl::Input & _input)
{
  _shader.bind();
  _shader.setUniform("view", this->transformation);
  _shader.setUniform("projection", this->projection);
  this->obj->initialize();
  this->obj->scale(glm::vec3(3.07, 3.07, 3.07));
  this->obj->setPos(glm::vec3(0, 0, 0));
  this->marvin->initialize();
  this->marvin->rotate(glm::vec3(0, -1, 0), -90);
  _context.updateClock(_clock);
  _context.updateInputs(_input);
}

bool		Animation::play(gdl::AShader & _shader, gdl::SdlContext & _context, gdl::Input & _input)
{
  if (_input.getKey(SDLK_SPACE))
    return (false);
  this->marvin->setPos(glm::vec3(pos, 0.9, 0.9));
  _shader.setUniform("view", this->transformation);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  this->obj->draw(_shader);
  this->marvin->draw(_shader);
  _shader.bind();
  _context.flush();
  if (pos >= 3.0)
    {
      marvin->rotate(glm::vec3(0, -1, 0), 180);
      OneD = 1;
    }
  else if (pos < -3.0)
    {
      marvin->rotate(glm::vec3(0, -1, 0), 180);
      OneD = 0;
    }
  OneD == 0 ? pos += 0.05 : pos -= 0.05;
  return (true);
}
