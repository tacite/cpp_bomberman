/*
** HighScore.cpp for  in /home/roledg/CURRENT/cpp_bomberman
** 
** Made by role-d_g
** Login   <roledg@epitech.net>
** 
** Started on  Sun Jun 15 21:24:34 2014 role-d_g
// Last update Sun Jun 15 23:20:03 2014 Lucas Vancompernolle
*/

#include	"HighScore.hpp"


HighScore::HighScore()
{
  this->projection = glm::perspective(60.0f, 800.0f / 600.0f, 0.1f, 100.0f);
  this->transformation  = glm::lookAt(glm::vec3(0, 0, 9), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
}

HighScore::~HighScore()
{
}

bool		HighScore::initialize(gdl::AShader & _shader, gdl::SdlContext & _context, gdl::Clock & _clock, gdl::Input & _input)
{
  _shader.bind();
  _shader.setUniform("view", this->transformation);
  _shader.setUniform("projection", this->projection);
      if (_texture.load("./Assets/highscore_sousmenu.tga") == false)
    { 
      std::cerr << "Cannot load the cube texture" << std::endl;
      return (false);
    }
  
  _geometry.pushVertex(glm::vec3(3.7, -3.1, 4.3)); 
  _geometry.pushVertex(glm::vec3(3.7, 3.1, 4.3)); 
  _geometry.pushVertex(glm::vec3(-3.7, 3.1, 4.3)); 
  _geometry.pushVertex(glm::vec3(-3.7, -3.1, 4.3));

  _geometry.pushUv(glm::vec2(0.0f, 0.0f)); 
  _geometry.pushUv(glm::vec2(1.0f, 0.0f)); 
  _geometry.pushUv(glm::vec2(1.0f, 1.0f)); 
  _geometry.pushUv(glm::vec2(0.0f, 1.0f)); 

  _geometry.build();
  _context.updateClock(_clock);
  _context.updateInputs(_input);
  return (true);
}

bool		HighScore::play(gdl::AShader & _shader, gdl::SdlContext & _context, gdl::Input & _input)
{ 
  glm::mat4		transform(1);


  _texture.bind();
  if (_input.getKey(SDLK_ESCAPE))
    return (false);
  _shader.setUniform("view", this->transformation);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  _geometry.draw(_shader, transform, GL_QUADS);
  _shader.bind();
  _context.flush();

  return (true);
}


