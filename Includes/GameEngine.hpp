/*
** GameEngine.hpp for  in /home/roledg/TMP/cpp_bomberman
** 
** Made by role-d_g
** Login   <roledg@epitech.net>
** 
** Started on  Tue Jun 10 23:29:35 2014 role-d_g
** Last update Sun Jun 15 22:27:11 2014 role-d_g
*/


#ifndef			__GAMEENGINE_HPP__
# define		__GAMEENGINE_HPP__

# include		<Game.hh>
# include		<SdlContext.hh>
# include		<GL/glew.h>
# include		<BasicShader.hh>
# include		<vector>

# include		"Human.hpp"
# include 		"Block.hpp"
# include		"Opt.hpp"
# include		"Animation.hpp"
# include		"Load.hpp"
# include		"HighScore.hpp"
# include		"Wall.hpp"
# include		"Box.hpp"
# include		"Bomb.hpp"
# include		"Floor.hpp"
# include		"Bomberman.hpp"
# include		"Bonus.hpp"
# include		"SkyBox.hpp"
# include		"Ia.hpp"

/*
** classe contenant fenêtre et évènements
*/

class			GameEngine : public gdl::Game
{
public:
  GameEngine();
  ~GameEngine();

  bool			initialize();	/* intialise GameEngine */
  bool			update();	/* Cherche à update */
  bool			game();
  void			marvin_die();
  void			finish_game(size_t);
  void			draw();		/* Draw */
  void			doAnimation();
  void			doHighScore();
  void			setBlockList(const std::vector<Block *> &);
  void 			setPlayerList(const std::vector<Player *> &);
  void			setIaList(const std::vector<Player*>	&);
  void			setSize(const int, const int);
  void			setWallList();
  void			clearList();
  bool			getSig() const;
  void			setSig(bool);

  bool			hasScreen();	/* Vérifie le boutton [SDL_QUIT] est pressé */

  template<typename T, typename S>
  S			getEnum()
  {
    glm::mat4		projection = glm::perspective(60.0f, 800.0f / 600.0f, 0.1f, 10000.0f);
    glm::mat4		transformation = glm::lookAt(glm::vec3(0, 0, 10),
						      glm::vec3(0, 0, 0),
						      glm::vec3(0, 1, 0));

    shader.bind();
    shader.setUniform("view", transformation);
    shader.setUniform("projection", projection);

    T			*t = new T;
    t->initialize();
    while (hasScreen() && t->update(input))
      {
	shader.setUniform("view", transformation);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	shader.bind();

	t->draw(context, shader);

	context.flush();
      }
    S			s = t->getMode();

    delete t;
    return (s);
  }
  
  void			setSingle(const int);

  int				getSizeX() const;
  int				getSizeY() const;
  const std::vector<Block *>	getBlock() const;
  const std::vector<Player* >	getPlayer() const;
  const std::vector<Player* >	getIa() const;
  const std::vector<Bonus *>	getBonus() const;

protected:
  /* Paramètres de settings */
  gdl::SdlContext	context;
  gdl::Clock		clock;
  gdl::Input		input;
  gdl::BasicShader	shader;
  gdl::BasicShader	shaderb;
  gdl::Geometry		_geometry;
  gdl::Texture		_texture;  
  double		time;

  /* Taille de la map */
  int			sizeX;
  int			sizeY;

  /* listes d'informations */
  std::vector<Block*>	listBlock;
  std::vector<Player*>	listPlayer;
  std::vector<Player*>	listIa;
  std::vector<Bonus*>	listBonus;
  std::vector<Fire *>	listFire;
  std::vector<Block*>	listWall;

  Bomb			*bomb;

  /* savoir si l'écran est actif ou non */
  bool			isScreen;
  bool			signal;
  bool 			hasBomb;
  int			single;
  
  bool 			maxBomb(const int idPlayer);
};

#endif			/* __GAMEENGINE_HPP__ */
