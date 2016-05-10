//
// MenuStart.cpp for bomber in /home/dupont-j/Perso/cpp_bomberman
// 
// Made by Jean-Antoine Dupont
// Login   <dupont_j@epitech.eu>
// 
// Started on  Tue May 27 15:08:22 2014 Jean-Antoine Dupont
// Last update Thu Jun 12 13:12:32 2014 Lucas Vancompernolle
//

#include	"MenuStart.hpp"

MenuStart::MenuStart() :
  pos(NEW_GAME)
{
}

MenuStart::~MenuStart()
{
}

bool			MenuStart::initialize()
{
  if (_texture.load("./Assets/newgame.tga") == false)
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

bool			MenuStart::update(gdl::Input & input)
{
  e_pos			oldpos;

  oldpos = pos;
  if (pos != NEW_GAME && input.getKey(SDLK_UP, true))
    pos = static_cast<e_pos>(static_cast<int>(pos) - 1);
  else if (pos != QUIT && input.getKey(SDLK_DOWN, true))
    pos = static_cast<e_pos>(static_cast<int>(pos) + 1);

  if (pos != oldpos)
    switch (pos)
      {
      case NEW_GAME:
	_texture.load("./Assets/newgame.tga");
	break;
      case LOAD:
	_texture.load("./Assets/load.tga");
	break;
      case OPTIONS:
	_texture.load("./Assets/options.tga");
	break;
      case HIGHSCORE:
	_texture.load("./Assets/highscore.tga");
	break;
      case QUIT:
	_texture.load("./Assets/Quit.tga");
	break;
      }

  if (input.getKey(SDLK_RETURN))
    return (false);
  return (true);
}

void			MenuStart::draw(gdl::SdlContext & context, gdl::BasicShader & shader)
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

MenuStart::e_pos		MenuStart::getMode() const
{
  return (pos);
}
