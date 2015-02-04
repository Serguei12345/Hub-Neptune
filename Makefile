##
## Makefile for ecosysteme in /home/ovoyan_s/rendu/ECOSYSTEME
## 
## Made by ovoyan_s
## Login   <ovoyan_s@epitech.net>
## 
## Started on  Wed Apr 30 16:52:06 2014 ovoyan_s
## Last update Mon Dec  1 00:20:30 2014 ovoyan_s
##

SRC_MAIN_CLASSES	=	MainClasses/sources

SRC_MY_CPP_LIBRARY	=	CppLibrary/sources

SRC_OPEN_GL		=	OpenGL/sources

SRC_PERLIN_NOISE	=	PerlinNoise/sources

SRC_SDL			=	SDL/sources

SRC_GLLIBRARY		=	MyGLLibrary/sources

SRC_PARSING		=	Parser/sources

SRC_MAP_CREATION	=	MapCreation/sources

HDR_GLLIBRARY		=	MyGLLibrary/headers

HDR_MAIN_CLASSES	=	MainClasses/headers

HDR_MY_CPP_LIBRARY	=	CppLibrary/headers

HDR_OPEN_GL		=	OpenGL/headers

HDR_PERLIN_NOISE	=	PerlinNoise/headers

HDR_SDL			=	SDL/headers

HDR_PARSING		=	Parser/headers

HDR_MAP_CREATION	=	MapCreation/headers

SRC		=	$(SRC_MAIN_CLASSES)/CCMHandler.cpp	\
			$(SRC_MAIN_CLASSES)/main.cpp		\
			$(SRC_MAIN_CLASSES)/Events.cpp		\
			$(SRC_MAIN_CLASSES)/EventActions.cpp	\
			$(SRC_MY_CPP_LIBRARY)/Containers.cpp	\
			$(SRC_MY_CPP_LIBRARY)/MyException.cpp	\
			$(SRC_MY_CPP_LIBRARY)/NbMath.cpp	\
			$(SRC_MY_CPP_LIBRARY)/Number.cpp	\
			$(SRC_MY_CPP_LIBRARY)/Random.cpp	\
			$(SRC_MY_CPP_LIBRARY)/Time.cpp		\
			$(SRC_OPEN_GL)/GLObject.cpp		\
			$(SRC_PERLIN_NOISE)/PerlinNoise.cpp	\
			$(SRC_SDL)/SDLMap.cpp			\
			$(SRC_GLLIBRARY)/myGLQuad.cpp		\
			$(SRC_GLLIBRARY)/MyGlScene.cpp		\
			$(SRC_GLLIBRARY)/MyGlMap.cpp		\
			$(SRC_PARSING)/Anomaly.cpp		\
			$(SRC_PARSING)/Chunk.cpp		\
			$(SRC_PARSING)/Parser.cpp		\
			$(SRC_PARSING)/Element.cpp		\
			$(SRC_MAP_CREATION)/EarthHydro.cpp	\
			$(SRC_MAP_CREATION)/MainPerlin.cpp	\
			$(SRC_MAP_CREATION)/MapAlteration.cpp	\
			$(SRC_MAP_CREATION)/MarineHydro.cpp	\
			$(SRC_MAP_CREATION)/RiverMaker.cpp	\
			$(SRC_MAP_CREATION)/River.cpp

OBJ		=	$(SRC:.cpp=.o)

NAME		=	ecosysteme

RM		=	rm -rf

CC		=	g++

LIBS		=	-I./$(HDR_MAIN_CLASSES)			\
			-I./$(HDR_MY_CPP_LIBRARY)		\
			-I./$(HDR_OPEN_GL)			\
			-I./$(HDR_PERLIN_NOISE)			\
			-I./$(HDR_SDL)				\
			-I./$(HDR_GLLIBRARY)			\
			-I./$(HDR_PARSING)			\
			-I./$(HDR_MAP_CREATION)			\
			-lSDL -lSDL_image			\
			-lGL -lGLU

CXXFLAGS	=	-Wall -Werror -W -Wextra -g3 $(LIBS)

all:			$(NAME)

$(NAME):		$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(LIBS)

clean:
			$(RM) $(OBJ)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

