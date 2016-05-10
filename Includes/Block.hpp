//
  /* Lance l'animation de départ */
// Block.hpp for bomber in /home/vancom_l/rendu/CPP/hannot_bomberman/cpp_bomberman/Includes
// 
// Made by Lucas Vancompernolle
// Login   <vancom_l@epitech.net>
// 
// Started on  Thu Jun  5 11:39:03 2014 Lucas Vancompernolle
// Last update Sun Jun 15 23:13:22 2014 Lucas Vancompernolle
//

#ifndef			__BLOCK_HPP__
# define		__BLOCK_HPP__

# include		<SdlContext.hh>
# include		<glm/glm.hpp>
# include		<glm/gtc/matrix_transform.hpp>
# include		<Texture.hh>
# include		<Geometry.hh>
# include		<Model.hh>
# include		<iostream>
# include		<cstdlib>
# include		<unistd.h>
# include		<math.h>
# include		<Game.hh>
# include		<GL/glew.h>
# include		<BasicShader.hh>
# include		<vector>
# include		<string>
# include		"Except.hpp"

class			Block
{
public:
  enum 			e_type
  {
    INDESTRUCTIBLE = 0,
    DESTRUCTIBLE,
    BOMBE,
    BONUS,
    FIRE,
    SKYBOX,
    FLOOR,
  };

protected:
  e_type 		type;
  glm::vec3		_scale;
  glm::vec3		_rotation;
  glm::vec3		_position;
  gdl::Geometry		_geometry;
  gdl::Texture		_texture;
  std::string		asset;
  
public:
  Block(const glm::vec3 &, const glm::vec3 &);
  virtual		~Block();

  bool			initialize();
  virtual bool		update(gdl::Clock &c);
  void			draw(gdl::AShader &);
  glm::mat4		getTransformation();

  void			translate(glm::vec3 const &);
  void			rotate(glm::vec3 const &, float);
  void			scale(glm::vec3 const &);

  glm::vec3 		getPos() const;  
  Block::e_type		getType() const;
  
  void 			setPos(const glm::vec3 &);
};

#endif			/* __BLOCK_HPP__ */
