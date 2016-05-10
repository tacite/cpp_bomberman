##
## Makefile for make in /home/cazheer/Documents/Cpp/Projet/cpp_bomberman
## 
## Made by Thomas Hannot
## Login   <hannot_t@epitech.net>
## 
## Started on  Tue May 13 13:34:23 2014 Thomas Hannot
## Last update Sun Jun 15 23:40:48 2014 role-d_g
##

NAME	=	bomberman

SRCS	=	Src/Main.cpp		\
		Src/Load.cpp		\
		Src/GameEngine.cpp	\
		Src/Engine.cpp		\
		Src/MenuStart.cpp	\
		Src/Block.cpp		\
		Src/Bomb.cpp		\
		Src/Wall.cpp		\
		Src/Box.cpp		\
		Src/Human.cpp		\
		Src/Player.cpp		\
		Src/Animation.cpp	\
		Src/SkyBox.cpp		\
		Src/Fire.cpp		\
		Src/Bonus.cpp		\
		Src/MenuGame.cpp	\
		Src/Floor.cpp		\
		Src/AnimBox.cpp	 	\
		Src/Opt.cpp		\
		Src/Loadgame.cpp	\
		Src/Loadsave.cpp	\
		Src/Save.cpp		\
		Src/HighScore.cpp	\
		Src/Ia.cpp		\


OBJS	=	$(SRCS:.cpp=.o)

FLAGS	+=	

INCLUDE	=	-I. -I./Includes/ -I./LibBomberman_linux_x64/includes/

LIB	=	-L./LibBomberman_linux_x64/libs/ -lsfml-audio -lgdl_gl -lGL -lGLEW  -lrt -lfbxsdk -lSDL2 -lpthread -ldl -L./lib/ -ltinyxml

CPP	=	g++

RM	=	rm -rf

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CPP) -o $(NAME) $(OBJS) $(FLAGS) $(INCLUDE) $(LIB)

.cpp.o	:
		$(CPP) -o $@ -c $< $(FLAGS) $(INCLUDE)

clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all