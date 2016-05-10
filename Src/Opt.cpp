/*
** Opt.cpp for  in /home/roledg/CURRENT/cpp_bomberman
** 
** Made by role-d_g
** Login   <roledg@epitech.net>
** 
** Started on  Sat Jun 14 17:55:55 2014 role-d_g
** Last update Sun Jun 15 00:29:00 2014 role-d_g
*/

# include	"Opt.hpp"

Opt::Opt() :
  pos(SINGLE_SOUND), h(NBPLAYER)
{
}

Opt::~Opt()
{
}

bool			Opt::initialize()
{
  if (_texture.load("./Assets/options_allon.tga") == false)
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

bool			Opt::update(gdl::Input & input)
{
  e_enum		oldenum;

  oldenum = pos;
  if (h == NBPLAYER && input.getKey(SDLK_DOWN, true))
    h = SOUND;
  else if (h == SOUND && input.getKey(SDLK_UP, true))
    h = NBPLAYER;
  if (((h == NBPLAYER && static_cast<int>(pos) % 2 == 0) ||
       (h == SOUND && pos < SINGLE_SOUND))
      && input.getKey(SDLK_LEFT, true))
    pos = static_cast<e_enum>(static_cast<int>(pos) + 1 + static_cast<int>(h));
  else if (((h == NBPLAYER && static_cast<int>(pos) % 2 == 1) ||
	    (h == SOUND && pos > MULTI_NOSOUND))
	   && input.getKey(SDLK_RIGHT, true))
    pos = static_cast<e_enum>(static_cast<int>(pos) - 1 - static_cast<int>(h));
  if (oldenum != pos)
    switch (pos)
      {
      case MULTI_SOUND:
	_texture.load("./Assets/options_allon.tga");
	break;
      case SINGLE_NOSOUND:
	_texture.load("./Assets/options_alloff.tga");
	break;
      case MULTI_NOSOUND:
	_texture.load("./Assets/options_on_off.tga");
	break;
      default:
	_texture.load("./Assets/options_off_on.tga");
      }
  if (input.getKey(SDLK_ESCAPE))
    return (false);
  return (true);
}

void			Opt::draw(gdl::SdlContext & context, gdl::BasicShader & shader)
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

Opt::e_enum		Opt::getMode() const
{
  return (pos);
}
