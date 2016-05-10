//
// Xml.hpp for Xml in /home/cazheer/Documents/Test/cpp_bomberman
// 
// Made by Thomas Hannot
// Login   <hannot_t@epitech.net>
// 
// Started on  Wed Jun  4 23:43:29 2014 Thomas Hannot
// Last update Sat Jun 14 19:50:02 2014 Lucas Vancompernolle
//

#ifndef		__XML_HPP__
# define	__XML_HPP__

# define	TIXML_USE_STL

# include	<tinyxml.h>
# include	<tinystr.h>

# define	MAP		"map"
# define	BOMB		"bomb"
# define	PLAYER		"player"
# define	BLOCK		"block"
# define	BONUS		"bonus"
# define	SIZEX		"sizeX"
# define	SIZEY		"sizeY"
# define	MIN_SIZE	(10)
# define	POSX		"posX"
# define	POSY		"posY"
# define	TYPE		"type"
# define	IDP		"idPlayer"
# define	TIME		"time"
# define	POWER		"power"
# define	SPEED		"speed"
# define	SCORE		"score"
# define	NB_BOMB		"nbBomb"
# define	PO_BOMB		"poBomb"
# define	NAME		"name"

#endif		/* __XML_HPP__ */
