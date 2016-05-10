//
// Bomberman.hpp for Bomberman in /home/cazheer/Documents/Cpp/Projet/cpp_bomberman
// 
// Made by Thomas Hannot
// Login   <hannot_t@epitech.net>
// 
// Started on  Fri May 23 11:28:00 2014 Thomas Hannot
// Last update Thu Jun 12 16:42:45 2014 Lucas Vancompernolle
//

#ifndef		__BOMBERMAN_HPP__
# define	__BOMBERMAN_HPP__

# include	<cstdlib>
# include	<iostream>
# include	"Except.hpp"

/*
**		Prog Default
*/

# define	PROGRAM_NAME		"[Bomberman]"

# define	SCREEN_X		1600
# define	SCREEN_Y		800

/*
**		Shaders
*/

# define	BASIC_SHADER_F		"./Shaders/basic.fp"
# define	BASIC_SHADER_V		"./Shaders/basic.vp"

/*
**		Assets
*/

/* GAME */
# define	GAME_WALL		"./assets/wall.tga"
# define	GAME_FLOOR		"./assets/grass.tga"

/* MENU */
# define	MENU_BG			"./assets/menu.tga"
# define	MENU_ARROW		"./assets/arrow.tga"

/*
**		Musics
*/

# define	MUSIC_MENU		"./Music/Menu_music.ogg"
# define	MUSIC_GAME		"./Music/Game_music.ogg"

/*
**		Default Values
*/

# define	DEFAULT_X		10
# define	DEFAULT_Y		10
# define	DEFAULT_Z		10

# define	NB_PLAYER		4
# define	NB_HUMAN		1

/*
**		Max Values
*/

# define	MAX_HUMAN		2

#endif		/* __BOMBERMAN_HPP__ */
