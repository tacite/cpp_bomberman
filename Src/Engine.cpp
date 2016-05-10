/*
** Engine.cpp for  in /home/roledg/BON_CPP/cpp_bomberman
** 
** Made by role-d_g
** Login   <roledg@epitech.net>
** 
** Started on  Sun Jun 15 12:32:30 2014 role-d_g
// Last update Sun Jun 15 23:17:48 2014 Lucas Vancompernolle
*/

#include	"Engine.hpp"
#include	<ctime>

Engine::Engine() :
  engine(new GameEngine), mode(START),
  music(new sf::Music), w_music(M_GAME),
  _name("map20x20_2"), nb_save(0)
{
}

Engine::~Engine() 
{
  delete engine;
  delete music;
}

void		Engine::initialize()
{
  if (!engine->initialize())
    throw Except("Cannot initialize GameEngine");
}

void		Engine::play()
{
  while (mode != QUIT && engine->hasScreen())
    switch (mode)
      {
      case START:
	Animation();
	break;
      case MENU:
	Menu();
	break;
      case GAME:
	Game();
	break;
      case MENU_GAME:
	MenuInGame();
	break;
      case LOAD:
	LoadSave();
	break;
      case SAVE:
	SaveGame();
	break;
      case NEW_GAME:
	LoadGame();
	break;
      case LAUNCH_GAME:
	NewGame();
	break;
      case OPTION_MENU:
	OptionMenu();
	break;
      case OPTION_GAME:
	MenuInGame();
	break;
      case HIGHSCORE:
	Highscore();
	break;
      default:
	mode = QUIT;
      }
}

bool		Engine::setMusic(const e_music _music, const bool force)
{
  if (w_music != _music && (w_music != M_NONE || force == true))
    {
      w_music = _music;
      if ((w_music == M_MENU && !music->OpenFromFile(MUSIC_MENU)) ||
	  (w_music == M_GAME && !music->OpenFromFile(MUSIC_GAME)))
	return (false);
      if (w_music != M_NONE && !music->GetLoop())
	music->SetLoop(true);
      if (w_music != M_NONE)
	music->Play();
      else
	music->Pause();
    }
  return (true);
}

void		Engine::Animation()
{
  if (!setMusic(M_MENU))
    std::cerr << "Warning: cannot load the music" << std::endl;
  this->engine->doAnimation();
  mode = MENU;
}

void		Engine::Menu()
{
  if (!setMusic(M_MENU))
    std::cerr << "Warning: cannot load the music" << std::endl;
  switch (engine->getEnum<MenuStart, MenuStart::e_pos>())
    {
    case MenuStart::NEW_GAME:
      mode = NEW_GAME;
      break;
    case MenuStart::LOAD:
      mode = LOAD;
      break;
    case MenuStart::OPTIONS:
      mode = OPTION_MENU;
      break;
    case MenuStart::HIGHSCORE:
      mode = HIGHSCORE;
      break;
    default:
      mode = QUIT;
    }
}

void		Engine::Game()
{
  if (!setMusic(M_GAME))
    std::cerr << "Warning: cannot load the music" << std::endl;
  while (engine->hasScreen() && engine->update())
    this->engine->draw();
  
  if (engine->getSig() == false)
    {
      engine->setSig(true);
      mode = START;
    }
  else
    mode = OPTION_GAME;  
}

void		Engine::MenuInGame()
{
  switch (engine->getEnum<MenuGame, MenuGame::e_pos>())
    {
    case MenuGame::PLAY:
      mode = GAME;
      break;
    case MenuGame::SAVE:
      mode = SAVE;
      break;
    case MenuGame::BACK:
      mode = START;
      break;
    default:
      mode = QUIT;
    }
}

void		Engine::LoadSave()
{
  switch (engine->getEnum<Loadsave, Loadsave::position>())
    {
    case Loadsave::FIRST:
      this->_name = "save1";
      mode = LAUNCH_GAME;
      break;
    case Loadsave::SECOND:
      this->_name = "save2";
      mode = LAUNCH_GAME;
      break;
    case Loadsave::THIRD:
      this->_name = "save3";
      mode = LAUNCH_GAME;
      break;
    case Loadsave::FOURTH:
      this->_name = "save4";
      mode = LAUNCH_GAME;
      break;
    case Loadsave::QUIT:
      mode = MENU;
    }
}

void		Engine::LoadGame()
{
  switch (engine->getEnum<Loadgame, Loadgame::position>())
    {
    case Loadgame::FIRST:
      this->_name = "map10x10_1";
      mode = LAUNCH_GAME;
      break;
    case Loadgame::SECOND:
      this->_name = "map20x20_1";
      mode = LAUNCH_GAME;
      break;
    case Loadgame::THIRD:
      this->_name = "map50x50_1";
      mode = LAUNCH_GAME;
      break;
    case Loadgame::FOURTH:
      {
	srand(time(NULL));
	int	random = rand() % 3;
	if (random == 0)
	  this->_name = "map10x10_1";
	else if (random == 1)
	  this->_name = "map20x20_1";
	else
	  this->_name = "map50x50_1";
	mode = LAUNCH_GAME;
	break;
      }
    case Loadgame::QUIT:
      mode = MENU;
      break;
    }
}

void		Engine::SaveGame()
{
  this->save = new Save();
  this->nb_save++;
  switch (this->nb_save)
    {
    case 1:
      save->saveFile(this->engine, "save1");
      break;
    case 2:
      save->saveFile(this->engine, "save2");
      break;
    case 3:
      save->saveFile(this->engine, "save3");
      break;
    case 4:
      save->saveFile(this->engine, "save4");
      break;
    default:
      std::cout << "[GAME] : No slot available." << std::endl;
      nb_save = -1;
      break;
    }
  if (nb_save != -1)
    std::cout << "[GAME] : Save save" << nb_save << ".xml creates with sucess." << std::endl;
  mode = GAME;
}

void		Engine::NewGame()
{
  Load _load;
  _load.parsing(this->_name);
  this->engine->clearList();
  this->engine->setSize(_load.getMapX(), _load.getMapY());
  this->engine->setWallList();
  this->engine->setBlockList(_load.getBlock());
  this->engine->setPlayerList(_load.getPlayer());
  this->engine->setIaList(_load.getIa());

  this->mode = Engine::GAME;
}

void		Engine::OptionMenu()
{
  switch (engine->getEnum<Opt, Opt::e_enum>())
    {
    case Opt::SINGLE_NOSOUND:
      engine->setSingle(0);
      setMusic(M_NONE);
      break;
    case Opt::SINGLE_SOUND:
      engine->setSingle(0);
      setMusic(M_MENU, true);
      break;
    case Opt::MULTI_NOSOUND:
      engine->setSingle(1);
      setMusic(M_NONE);
      break;
    default:
      engine->setSingle(1);
      setMusic(M_MENU, true);
    }
  mode = MENU;
}

void		Engine::OptionGame()
{
  MenuInGame();
}

void		Engine::Highscore()
{
  this->engine->doHighScore();
  mode = MENU;
}
