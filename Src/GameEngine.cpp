/*
** GameEngine.cpp for  in /home/roledg/TMP/cpp_bomberman
** 
** Made by role-d_g
** Login   <roledg@epitech.net>
** 
** Started on  Tue Jun 10 23:29:48 2014 role-d_g
** Last update Sun Jun 15 23:39:27 2014 role-d_g
*/


#include 		"Block.hpp"
#include		"GameEngine.hpp"

GameEngine::GameEngine() :
  isScreen(false)
{
  this->listBlock.clear();
  this->listWall.clear();
  this->listBonus.clear();
  this->listPlayer.clear();
  this->listFire.clear();
  this->hasBomb = false;
}

GameEngine::~GameEngine()
{
  clearList();
}

bool			GameEngine::initialize()
{
  if (!context.start(SCREEN_X, SCREEN_Y, PROGRAM_NAME))
    {
      std::cerr << "SdlContext start: fail" << std::endl;
      return (false);
    }
  glEnable(GL_DEPTH_TEST);
  if (!shader.load(BASIC_SHADER_F, GL_FRAGMENT_SHADER)
      || !shader.load(BASIC_SHADER_V, GL_VERTEX_SHADER)
      || !shader.build())
    {
      std::cerr << "Shader load/build: fail" << std::endl;
      return (false);
    }
  if (!shaderb.load(BASIC_SHADER_F, GL_FRAGMENT_SHADER)
      || !shaderb.load(BASIC_SHADER_V, GL_VERTEX_SHADER)
      || !shaderb.build())
    {
      std::cerr << "Shader load/build: fail" << std::endl;
      return (false);
    }
  std::cout << "Game loaded. Have fun !" << std::endl;
  signal = true;
  isScreen = true;
  return (true);
}

bool			GameEngine::update()
{
  if (input.getKey(SDLK_ESCAPE))
    return (false);

  if (signal == false)
    return (false);

  glm::mat4		projection;
  glm::mat4		transformation;
  glm::mat4		projectionb;
  glm::mat4		transformationb;

  projection = glm::perspective(60.0f, static_cast<float>(SCREEN_X) / static_cast<float>(SCREEN_Y), 0.1f, 1000.0f);
  transformation = glm::lookAt(glm::vec3(0, -3, 5), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
  this->shader.bind();
  this->shader.setUniform("view", transformation);
  this->shader.setUniform("projection", projection);
  projectionb = glm::perspective(60.0f, static_cast<float>(SCREEN_X) / static_cast<float>(SCREEN_Y), 0.1f, 1000.0f);
  transformationb = glm::lookAt(glm::vec3(0, -3, 5), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
  this->shaderb.bind();
  this->shaderb.setUniform("view", transformationb);
  this->shaderb.setUniform("projection", projectionb);
  time = 0.0;
  if (single == 1 && listPlayer.size() > 1)
    {
      std::vector<Player *>::iterator it;
      it = this->listPlayer.begin();
      for (size_t a = 0; a < 1; a++)
	it++;
      this->listPlayer.erase(it);
    }

  if (input.getKey(SDLK_KP_1, true) && this->maxBomb(listPlayer[0]->getId()) == true)
    {
      Block *bomb = new Bomb(glm::vec3(round(listPlayer[0]->getPosX()), round(listPlayer[0]->getPosY()), listPlayer[0]->getPosH()), glm::vec3(1, 1, 1), listPlayer[0]->getId(), this->listPlayer[0]->getPower());
      if (bomb->initialize() == false)
	throw Except("Error on Bomb initialize");
      this->listBlock.push_back(bomb);
    }
  if (input.getKey(SDLK_SPACE, true) && listPlayer.size() > 1 && this->maxBomb(listPlayer[1]->getId()) == true)
    {
      Block *bomb = new Bomb(glm::vec3(round(listPlayer[1]->getPosX()), round(listPlayer[1]->getPosY()), listPlayer[1]->getPosH()), glm::vec3(1, 1, 1), listPlayer[1]->getId(), this->listPlayer[0]->getPower());
      if (bomb->initialize() == false)
	throw Except("Error on Bomb initialize");
      this->listBlock.push_back(bomb);
    } 
  
  for (size_t i = 0; i < listBlock.size(); i++)
  {
    if (this->listBlock[i]->getType() == Block::BOMBE)
    {
      if (this->listBlock[i]->update(this->clock) == true)
      {
	this->bomb = static_cast<Bomb *>(this->listBlock[i]);
	this->hasBomb = true;
	this->bomb->destroy(this->listBlock, this->listWall, this->listBonus);
	this->context.flush();
	std::vector<Block *>::iterator it = this->listBlock.begin();
	for (size_t a = 0; a < i; ++a, ++it);
	this->listBlock.erase(it);
      }
    }
    else if (!this->listBlock[i]->update(this->clock))
      throw Except("Error while updating block list");
  }
  for (size_t i = 0; i < listBonus.size(); i++)
    if (!this->listBonus[i]->update(this->clock))
      throw Except("Error while updating bonus list");
  for (size_t i = 0; i < listWall.size(); i++)
    if (!this->listWall[i]->update(this->clock))
      throw Except("Error while updating wall list");
  for (size_t i = 0; i < listIa.size(); i++)
    if (!static_cast<Ia *>(this->listIa[i])->update_ia(this->listBlock, this->listWall,
							this->listPlayer, this->listIa, this->clock))
      throw Except("Error while updating wall list");
  if (listPlayer.size() > 1)
    {
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      glViewport(0, 0, SCREEN_X / 2, SCREEN_Y);  
      shader.bind();
      if (!this->listPlayer[0]->update(this->shader, this->clock, this->input, this->listBlock, this->listWall, this->listBonus))
	throw Except("Error while updating player list");
     if (listPlayer.size() >= 1)  
       this->listPlayer[0]->draw(this->shader);
     if (listPlayer.size() >= 2)
       this->listPlayer[1]->draw(this->shaderb);
      glViewport(SCREEN_X / 2, 0, SCREEN_X / 2, SCREEN_Y);  
      shaderb.bind();
      if (!this->listPlayer[1]->update(this->shaderb, this->clock, this->input, this->listBlock, this->listWall, this->listBonus))
	throw Except("Error while updating player list");
      if (listPlayer.size() >= 1)
	this->listPlayer[0]->draw(this->shader);
      if (listPlayer.size() >= 2)
	this->listPlayer[1]->draw(this->shaderb);
    }
  else
    {
      this->shader.bind();
      for (size_t i = 0; i < listPlayer.size(); i++)
	{
	  this->listPlayer[i]->update(this->shader, this->clock, this->input, this->listBlock, this->listWall, this->listBonus);
	}
    }
  return (true);
}

void			GameEngine::draw()
{
  if (listPlayer.size() > 1)
    {
      glViewport(0, 0, SCREEN_X / 2, SCREEN_Y);
      for (size_t i = 0; i < listBlock.size(); i++)
	this->listBlock[i]->draw(this->shader);
      for (size_t i = 0; i < listWall.size(); i++)
	this->listWall[i]->draw(this->shader);
      for (size_t i = 0; i < listBonus.size(); i++)
	this->listBonus[i]->draw(this->shader);
      for (size_t i = 0; i < listIa.size(); i++)
	this->listIa[i]->draw(this->shader);
      if (this->hasBomb == true)
	{
	  this->listFire = this->bomb->getFire();
	  this->bomb->setStart(this->clock.getElapsed());
	  if (bomb->getStart() < 1.0)
	    {
	      for (size_t i = 0; i < listFire.size(); ++i)
		listFire[i]->draw(this->shader);
	      this->marvin_die();
	    }
	  else
	    listFire.clear();
	}
      glViewport(SCREEN_X / 2, 0, SCREEN_X / 2, SCREEN_Y);  
      for (size_t i = 0; i < listBlock.size(); i++)
	this->listBlock[i]->draw(this->shaderb);
      for (size_t i = 0; i < listWall.size(); i++)
	this->listWall[i]->draw(this->shaderb);
      for (size_t i = 0; i < listBonus.size(); i++)
	this->listBonus[i]->draw(this->shaderb);
      for (size_t i = 0; i < listIa.size(); i++)
	this->listIa[i]->draw(this->shader);
      if (this->hasBomb == true)
	{
	  this->listFire = this->bomb->getFire();
	  this->bomb->setStart(this->clock.getElapsed());
	  if (bomb->getStart() < 1.0)
	    {
	      for (size_t i = 0; i < listFire.size(); ++i)
		listFire[i]->draw(this->shaderb);
	      this->marvin_die();
	    }
	  else
	    listFire.clear();
	}
      context.flush();
      glViewport(0, 0, SCREEN_X, SCREEN_Y);
    }
  else
    {
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      for (size_t i = 0; i < listBlock.size(); i++)
	this->listBlock[i]->draw(this->shader);
      for (size_t i = 0; i < listWall.size(); i++)
	this->listWall[i]->draw(this->shader);
      for (size_t i = 0; i < listBonus.size(); i++)
	this->listBonus[i]->draw(this->shader);
      for (size_t i = 0; i < listPlayer.size(); i++)
	this->listPlayer[i]->draw(this->shader);
      for (size_t i = 0; i < listIa.size(); i++)
	this->listIa[i]->draw(this->shader);
      if (this->hasBomb == true)
	{
	  this->listFire = this->bomb->getFire();
	  this->bomb->setStart(this->clock.getElapsed());
	  if (bomb->getStart() < 1.0)
	    {
	      for (size_t i = 0; i < listFire.size(); ++i)
		listFire[i]->draw(this->shader);
	      this->marvin_die();
	    }
	  else
	    listFire.clear();
	}
     context.flush(); 
    }
}

void				GameEngine::marvin_die()
{
  float				a, b;
  size_t			position;
  
  position = 0;
  for (size_t i = 0; i < this->listPlayer.size(); ++i)
    {
      if (listPlayer[i]->getType() == Player::HUMAN)
	{
	  
	  a = round(this->listPlayer[i]->getPosX());
	  b = round(this->listPlayer[i]->getPosY());
	  position = i;
	}
      for (size_t i = 0; i < this->listFire.size(); ++i)
	if (round(this->listFire[i]->getPos().x) == a && round(this->listFire[i]->getPos().y) == b)
	  {
	    std::vector<Player *>::iterator it;
	    
	    it = this->listPlayer.begin();
	    for (size_t a = 0; a < position; a++)
	      it++;
	    listPlayer[position]->setPos(glm::vec3(0, 0, 0));
	    listPlayer[position]->update(this->shader, this->clock, this->input, this->listBlock, this->listWall, this->listBonus);
	    this->listPlayer.erase(it);
	    if (single == 0 && listPlayer.size() == 1 && position > 0)
	      {
		std::cout << "Player one wins ! Congratulation !" << std::endl;
		glViewport(0, 0, SCREEN_X, SCREEN_Y);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		finish_game(1);
		while (time < 8.0)
		  {
		    time += clock.getElapsed();
		    usleep(30000);
		  }
	      }
	    else if (single == 0 && listPlayer.size() == 1 && position == 0)
	      {
		std::cout << "Player two wins ! Congratulation !" << std::endl;
		glViewport(0, 0, SCREEN_X, SCREEN_Y);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		finish_game(2);
		while (time < 8.0)
		  {
		    time += clock.getElapsed();
		    usleep(30000);
		  }
	      }
	    else
	      {
		std::cout << "You loose !" << std::endl;
		glViewport(0, 0, SCREEN_X, SCREEN_Y);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		finish_game(3);
		while (time < 8.0)
		  {
		    time += clock.getElapsed();
		    usleep(30000);
		  }
	      }
	    glViewport(0, 0, SCREEN_X, SCREEN_Y);
	    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	    clearList();
	    hasBomb = false;
	    signal = false;
	  }
    }
}

void			GameEngine::finish_game(size_t player)
{
  glm::mat4		transform(1);
  glm::vec3		position(0, -3, 0);
  glm::vec3		scale(0.5, 0.5, 0.9);


  if (player == 1)
    {
      if (_texture.load("./Assets/firstplayer.tga") == false)
	throw Except("Cannot load the cube texture");
    }
  else if (player == 2)
    {
      if (_texture.load("./Assets/secondplayer.tga") == false)
	throw Except("Cannot load the cube texture");  
    }
  else
    {
      if (_texture.load("./Assets/loose.tga") == false)
	throw Except("Cannot load the cube texture");  
    }
  _geometry.pushVertex(glm::vec3(3.5, -3.5, 4.3)); 
  _geometry.pushVertex(glm::vec3(3.5, 3.5, 4.3)); 
  _geometry.pushVertex(glm::vec3(-3.5, 3.5, 4.3)); 
  _geometry.pushVertex(glm::vec3(-3.5, -3.5, 4.3));

  _geometry.pushUv(glm::vec2(0.0f, 0.0f)); 
  _geometry.pushUv(glm::vec2(1.0f, 0.0f)); 
  _geometry.pushUv(glm::vec2(1.0f, 1.0f)); 
  _geometry.pushUv(glm::vec2(0.0f, 1.0f)); 

  _geometry.build();
  transform = glm::translate(transform, position);
  transform = glm::scale(transform, scale);
  
  _texture.bind();
  _geometry.draw(shader, transform, GL_QUADS);

  context.flush();
}

bool			GameEngine::hasScreen()
{
  if (isScreen)
    {
      context.updateClock(clock);
      context.updateInputs(input);
      
      if (input.getInput(SDL_QUIT))
	isScreen = false;
    }
  return (isScreen);
}

bool			GameEngine::getSig() const
{
  return (signal);
}

void			GameEngine::setSig(bool cond)
{
  signal = cond;
}

bool			GameEngine::game()
{
  return (false);
}

void			GameEngine::setBlockList(const std::vector<Block *> &l)
{
  this->listBlock = l;
}

void 			GameEngine::setPlayerList(const std::vector<Player *> &l)
{
  this->listPlayer = l;
  
  if (l.size() > 1)
    l[1]->setNumber(1);
}

void 			GameEngine::setIaList(const std::vector<Player *> &l)
{
  this->listIa = l;
}

bool 			GameEngine::maxBomb(const int idPlayer)
{
    int			nb;
    size_t		i;
    Bomb		*bomb;

    nb = 0;
    i = 0;
    for (i = 0; i < this->listBlock.size(); ++i)
      if (this->listBlock[i]->getType() == Block::BOMBE)
	{
	  bomb = static_cast<Bomb *>(this->listBlock[i]);
	  if (bomb->getId() == idPlayer)
	    nb++;
	}
    for (i = 0; i < this->listPlayer.size(); ++i)
      if (this->listPlayer[i]->getType() == Player::HUMAN && this->listPlayer[i]->getId() == idPlayer)
	break;
    if (nb >= this->listPlayer[i]->getNbBomb())
      return (false);
    return (true);
}

void			GameEngine::doAnimation()
{
  Animation		*anim = new Animation;

  anim->initialize(this->shader, this->context, this->clock, this->input);
  while (hasScreen() && anim->play(this->shader, this->context, this->input));
  delete anim;
}

void			GameEngine::doHighScore()
{
  HighScore		*high = new HighScore;

  high->initialize(this->shader, this->context, this->clock, this->input);
  while (hasScreen() && high->play(this->shader, this->context, this->input));
  delete high;
}

void			GameEngine::setSize(const int x, const int y)
{
  this->sizeX = x;
  this->sizeY = y;
}

void			GameEngine::setWallList()
{
  int			i;

  i = -1;
  while (i < this->sizeX + 2)
    {
      Block *wall_1 = new Wall(glm::vec3(i, -1, 0), glm::vec3(1, 1, 1));
      Block *wall_2 = new Wall(glm::vec3(i, this->sizeY + 1, 0), glm::vec3(1, 1, 1));
      if (wall_1->initialize() == false)
	throw Except("Error on Wall initialize");
      if (wall_2->initialize() == false)
	throw Except("Error on Wall initialize");
      this->listWall.push_back(wall_1);
      this->listWall.push_back(wall_2);
      i++;
    }
  i = 0;
  while (i < this->sizeY + 1)
    {
      Block *wall_1 = new Wall(glm::vec3(-1, i, 0), glm::vec3(1, 1, 1));
      Block *wall_2 = new Wall(glm::vec3(this->sizeX + 1, i, 0), glm::vec3(1, 1, 1));
      if (wall_1->initialize() == false)
	throw Except("Error on Wall initialize");
      if (wall_2->initialize() == false)
	throw Except("Error on Wall initialize");
      this->listWall.push_back(wall_1);
      this->listWall.push_back(wall_2);
      i++;
    }
  Block *ground = new Floor(glm::vec3((this->sizeX) / 2, (this->sizeY) / 2, -1), glm::vec3(this->sizeX + 2, this->sizeY + 2, 1));
  if (ground->initialize() == false)
    throw Except("Error on Ground init");
  this->listWall.push_back(ground);
  Block *sky = new SkyBox(glm::vec3(this->sizeX / 2, this->sizeY / 2, -1), glm::vec3(2 * this->sizeX, 2 * this->sizeY, 20));
  if (sky->initialize() == false)
    throw Except("Error on SkyBox init");
  this->listWall.push_back(sky);
}

void		GameEngine::clearList()
{
  for (; this->listBlock.size() > 0; this->listBlock.pop_back())
    delete this->listBlock.back();
  for (; this->listPlayer.size() > 0; this->listPlayer.pop_back())
    delete this->listPlayer.back();
  for (; this->listFire.size() > 0; this->listFire.pop_back())
    delete this->listFire.back();
  for (; this->listWall.size() > 0; this->listWall.pop_back())
    delete this->listWall.back();
  for (; this->listBonus.size() > 0; this->listBonus.pop_back())
    delete this->listBonus.back();
  for (; this->listIa.size() > 0; this->listIa.pop_back())
    delete this->listIa.back();
}

void		GameEngine::setSingle(const int _single)
{
  single = _single;
}

int				GameEngine::getSizeX() const
{
  return sizeX;
}

int				GameEngine::getSizeY() const
{
  return sizeY;
}

const std::vector<Block *>	GameEngine::getBlock() const
{
  return listBlock;
}

const std::vector<Player *>	GameEngine::getPlayer() const
{
  return listPlayer;
}

const std::vector<Player *>	GameEngine::getIa() const
{
  return listIa;
}

const std::vector<Bonus *>	GameEngine::getBonus() const
{
  return listBonus;
}
