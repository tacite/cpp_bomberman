# include	"Loadsave.hpp"

Loadsave::Loadsave() : _pos(FIRST)
{
}

Loadsave::~Loadsave()
{
}

bool			Loadsave::initialize()
{
  if (_texture.load("./Assets/save1.tga") == false)
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

bool			Loadsave::update(gdl::Input & input)
{
  position		old_pos;
  
  old_pos = this->_pos;
  if (input.getKey(SDLK_LEFT, true))
  {
    if (this->_pos == SECOND)
      this->_pos = FIRST;
    else if (this->_pos == THIRD)
      this->_pos = SECOND;
    else if (this->_pos == FIRST)
      this->_pos = FOURTH;
    else if (this->_pos == FOURTH)
      this->_pos = THIRD;
  }
  if (input.getKey(SDLK_RIGHT, true))
  {
    if (this->_pos == SECOND)
      this->_pos = THIRD;
    else if (this->_pos == FIRST)
      this->_pos = SECOND;
    else if (this->_pos == THIRD)
      this->_pos = FOURTH;
    else if (this->_pos == FOURTH)
      this->_pos = FIRST;
  }
  if (this->_pos != old_pos)
  {
  switch (this->_pos)
  {
    case FIRST:
      _texture.load("./Assets/save1.tga");
      break;
    case SECOND:
      _texture.load("./Assets/save2.tga");
      break;
    case THIRD:
      _texture.load("./Assets/save3.tga");
      break;
    case FOURTH:
      _texture.load("./Assets/save4.tga");
      break;
  }
  }
  if (input.getKey(SDLK_ESCAPE, true))
  {
    this->_pos = QUIT; 
    return (false);
  }
  if (input.getKey(SDLK_SPACE, true))
  {
    return (false);
  }
  return (true);
}

void			Loadsave::draw(gdl::SdlContext & context, gdl::BasicShader & shader)
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

Loadsave::position		Loadsave::getMode() const
{
  return (this->_pos);
}
