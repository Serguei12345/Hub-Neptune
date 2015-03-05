##
## Makefile for PGraph in /home/ovoyan_s/Hub-Neptune/Sources/Plugins/PGraph
## 
## Made by ovoyan_s
## Login   <ovoyan_s@epitech.net>
## 
## Started on  Wed Feb  4 20:32:21 2015 ovoyan_s
## Last update Thu Mar  5 20:05:21 2015 ovoyan_s
##

SRC_FILES	=	sources

HDR_FILES	=	headers

SRC		=	$(SRC_FILES)/PGraph.cpp			\
			$(SRC_FILES)/APlugin.cpp		\
			$(SRC_FILES)/EventActions.cpp		\
			$(SRC_FILES)/FileManager.cpp		\
			$(SRC_FILES)/Containers.cpp		\
			$(SRC_FILES)/Random.cpp			\
			$(SRC_FILES)/Time.cpp			\
			$(SRC_FILES)/MyException.cpp		\

OBJ		=	$(SRC:.cpp=.o)

CC		=	g++

RM		=	rm -rf

CXXFLAGS	=	-Wall -Werror -Wextra		\
			-fPIC				\
			-ansi				\
			-I./$(HDR_FILES)		\
			-lSDL -lSDL_image		\
			-lGL -lGLU -ldl

NAME		=	PGraph.so

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -shared -o $(NAME) $(OBJ) $(LIBS)
		mv $(NAME) ../../../Plugins

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
