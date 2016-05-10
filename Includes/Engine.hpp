/*
** Engine.hpp for  in /home/roledg/BON_CPP/cpp_bomberman
** 
** Made by role-d_g
** Login   <roledg@epitech.net>
** 
** Started on  Sun Jun 15 13:32:43 2014 role-d_g
** Last update Sun Jun 15 17:36:43 2014 role-d_g
*/

#ifndef		__ENGINE_HPP__
# define	__ENGINE_HPP__

# include	<SFML/Audio.hpp>
# include	<iostream>
# include	"Bomberman.hpp"
# include	"GameEngine.hpp"
# include	"MenuStart.hpp"
# include	"MenuGame.hpp"
# include	"Opt.hpp"
# include	"Loadgame.hpp"
# include	"Save.hpp"
# include	"Loadsave.hpp"

/*
 * Classe principale
 * 	=> permet le changement entre les différents modes
 */

class		Engine
{
public:
  enum		e_mode
    {
      START,			/* Animation de départ */

      MENU,			/* Menu de départ */
      GAME,			/* Jeu */
      MENU_GAME,	       	/* Menu pendant la partie */

      LOAD,			/* chargement des saves */
      SAVE,			/* save la partie en cours */

      NEW_GAME,			/* Chargement d'une partie */
      LAUNCH_GAME,		/*lancement d'une partie */
      
      OPTION_MENU,		/* Mode option lancé depuis le menu */
      OPTION_GAME,		/* Mode option lancé depuis le jeu */

      HIGHSCORE,       		/* Affichage des Highscores */

      QUIT			/* Quitte le jeu */
    };

  enum		e_music
    {
      M_MENU,
      M_GAME,
      M_NONE
    };

  Engine();
  ~Engine();

  void		initialize();	/* Initialise la fenêtre */	
  void		play();		/* lance la boucle de jeu */

  bool		setMusic(const e_music, const bool force = false);

private:
  void		Animation();

  void		Menu();
  void		Game();
  void		MenuInGame();

  void		LoadSave();
  void		SaveGame();

  void		LoadGame();
  void		NewGame();

  void		OptionMenu();
  void		OptionGame();

  void		Highscore();

private :  
  GameEngine	*engine;
  Save		*save;
  int		nb_save;
  e_mode	mode;
  
  std::string	_name;
  sf::Music	*music;
  e_music	w_music;
};

#endif		/* __ENGINE_HPP__ */
