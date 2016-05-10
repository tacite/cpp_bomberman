/*
** MenuGame.cpp for  in /home/roledg/BON_CPP/cpp_bomberman
** 
** Made by role-d_g
** Login   <roledg@epitech.net>
** 
** Started on  Sun Jun 15 12:33:25 2014 role-d_g
** Last update Sun Jun 15 12:43:48 2014 role-d_g
*/

#include	"MenuGame.hpp"

MenuGame::MenuGame() :
  pos(PLAY)
{
}

MenuGame::~MenuGame()
{
  
}

bool		MenuGame::initialize()
{
    if (_texture.load("./Assets/pause1.tga") == false)
    { 
      std::cerr << "Cannot load the cube texture" << std::endl;
      return (false);
    }

  _geometry.pushVertex(glm::vec3(4.3, -4.3, 4.3)); 
  _geometry.pushVertex(glm::vec3(4.3, 4.3, 4.3)); 
  _geometry.pushVertex(glm::vec3(-4.3, 4.3, 4.3)); 
  _geometry.pushVertex(glm::vec3(-4.3, -4.3, 4.3));

  _geometry.pushUv(glm::vec2(0.0f, 0.0f)); 
  _geometry.pushUv(glm::vec2(1.0f, 0.0f)); 
  _geometry.pushUv(glm::vec2(1.0f, 1.0f)); 
  _geometry.pushUv(glm::vec2(0.0f, 1.0f)); 

  _geometry.build();
  return (true);
}

bool		MenuGame::update(gdl::Input &input)
{
  e_pos		oldpos;
  
  oldpos = pos;
  if (pos != PLAY && input.getKey(SDLK_UP, true))
    pos = static_cast<e_pos>(static_cast<int>(pos - 1));
  else if (pos != QUIT && input.getKey(SDLK_DOWN, true))
    pos = static_cast<e_pos>(static_cast<int>(pos + 1));

  if (oldpos != pos)
      switch (pos)
      {
      case PLAY:
	_texture.load("./Assets/pause1.tga");
	break;
      case SAVE:
	_texture.load("./Assets/pause2.tga");
	break;
      case BACK:
	_texture.load("./Assets/pause3.tga");
	break;
      default:
	_texture.load("./Assets/pause4.tga");
      }
  
  if (input.getKey(SDLK_RETURN))
    return (false);
  return (true);
}

void		MenuGame::draw(gdl::SdlContext &context, gdl::AShader &shader)
{
  (void)context;
  glm::mat4		transform(1);
  glm::vec3		position(0, 0, 0);
  glm::vec3		scale(1.1, 0.9, 0.9);

  transform = glm::translate(transform, position);
  transform = glm::scale(transform, scale);
  _texture.bind();
  _geometry.draw(shader, transform, GL_QUADS);
}

MenuGame::e_pos	MenuGame::getMode() const
{
  return (this->pos);
}
