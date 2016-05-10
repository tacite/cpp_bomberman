//
// Block.cpp for bomberman in /home/vancom_l/rendu/CPP/hannot_bomberman/cpp_bomberman/Src
// 
// Made by Lucas Vancompernolle
// Login   <vancom_l@epitech.net>
// 
// Started on  Thu Jun  5 12:20:38 2014 Lucas Vancompernolle
// Last update Sun Jun 15 23:22:38 2014 Lucas Vancompernolle
//

#include 	"Block.hpp"

Block::Block(const glm::vec3 &pos, const glm::vec3 &sc)
{
  this->_scale = sc;
  this->_position = pos;
  this->_rotation = glm::vec3(0, 0, 0);
}

Block::~Block()
{
}

bool		Block::initialize()
{
  if (this->_texture.load(this->asset) == false)
    {
      std::cerr << "Can not load the texture : " << this->asset << std::endl;
      return (false);
    }

  this->_geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5)); 
  this->_geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5)); 
  this->_geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5)); 
  this->_geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));

  this->_geometry.pushUv(glm::vec2(0.0f, 0.0f)); 
  this->_geometry.pushUv(glm::vec2(1.0f, 0.0f)); 
  this->_geometry.pushUv(glm::vec2(1.0f, 1.0f)); 
  this->_geometry.pushUv(glm::vec2(0.0f, 1.0f)); 

  this->_geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5)); 
  this->_geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5)); 
  this->_geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5)); 
  this->_geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5)); 

  this->_geometry.pushUv(glm::vec2(0.0f, 0.0f)); 
  this->_geometry.pushUv(glm::vec2(1.0f, 0.0f)); 
  this->_geometry.pushUv(glm::vec2(1.0f, 1.0f));
  this->_geometry.pushUv(glm::vec2(0.0f, 1.0f)); 

  this->_geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5)); 
  this->_geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5)); 
  this->_geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5)); 
  this->_geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5)); 

  this->_geometry.pushUv(glm::vec2(0.0f, 0.0f)); 
  this->_geometry.pushUv(glm::vec2(1.0f, 0.0f)); 
  this->_geometry.pushUv(glm::vec2(1.0f, 1.0f)); 
  this->_geometry.pushUv(glm::vec2(0.0f, 1.0f)); 

  this->_geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5)); 
  this->_geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5)); 
  this->_geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5)); 
  this->_geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5)); 

  this->_geometry.pushUv(glm::vec2(0.0f, 0.0f)); 
  this->_geometry.pushUv(glm::vec2(1.0f, 0.0f)); 
  this->_geometry.pushUv(glm::vec2(1.0f, 1.0f)); 
  this->_geometry.pushUv(glm::vec2(0.0f, 1.0f)); 

  this->_geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5)); 
  this->_geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5)); 
  this->_geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5)); 
  this->_geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5)); 

  this->_geometry.pushUv(glm::vec2(0.0f, 0.0f)); 
  this->_geometry.pushUv(glm::vec2(1.0f, 0.0f)); 
  this->_geometry.pushUv(glm::vec2(1.0f, 1.0f)); 
  this->_geometry.pushUv(glm::vec2(0.0f, 1.0f)); 

  this->_geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
  this->_geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
  this->_geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
  this->_geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));

  this->_geometry.pushUv(glm::vec2(0.0f, 0.0f));
  this->_geometry.pushUv(glm::vec2(1.0f, 0.0f));
  this->_geometry.pushUv(glm::vec2(1.0f, 1.0f));
  this->_geometry.pushUv(glm::vec2(0.0f, 1.0f));

  this->_geometry.build();
  return (true);
}

bool		Block::update(gdl::Clock &c)
{
  (void)c;
  return (true);
}

glm::mat4	Block::getTransformation()
{
  glm::mat4		transform(1);

  transform = glm::translate(transform, this->_position);
  transform = glm::rotate(transform, this->_rotation.x, glm::vec3(1, 0, 0));
  transform = glm::rotate(transform, this->_rotation.y, glm::vec3(0, 1, 0));
  transform = glm::rotate(transform, this->_rotation.z, glm::vec3(0, 0, 1));
  transform = glm::scale(transform, this->_scale);
  return (transform);
}

void		Block::draw(gdl::AShader &s)
{
  this->_texture.bind();
  this->_geometry.draw(s, this->getTransformation(), GL_QUADS);
}

void		Block::translate(glm::vec3 const &v)
{
  this->_position += v;
}

void		Block::rotate(glm::vec3 const &v, const float a)
{
  this->_rotation += (v * a);
}

void		Block::scale(glm::vec3 const &s)
{
  this->_scale *= s;
}

Block::e_type Block::getType() const
{
   return (this->type);
}

glm::vec3 Block::getPos() const
{
  return (this->_position);
}

void Block::setPos(const glm::vec3 &p)
{
  this->_position = p; 
}
