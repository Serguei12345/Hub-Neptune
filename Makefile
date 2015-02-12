##
## Makefile for ecosysteme in /home/ovoyan_s/rendu/ECOSYSTEME
## 
## Made by ovoyan_s
## Login   <ovoyan_s@epitech.net>
## 
## Started on  Wed Apr 30 16:52:06 2014 ovoyan_s
## Last update Tue Feb 10 11:49:56 2015 ovoyan_s
##

SRC_FILES	=	sources

HDR_FILES	=	headers

TOOLS		=	Sources/Tools

PLUGINS		=	Sources/Plugins

CORE		=	Sources/Core

SRC		=	main.cpp 				\
			$(TOOLS)/$(SRC_FILES)/FileManager.cpp	\
			$(TOOLS)/$(SRC_FILES)/MyException.cpp	\
			$(TOOLS)/$(SRC_FILES)/Containers.cpp	\
			$(TOOLS)/$(SRC_FILES)/Time.cpp		\
			$(TOOLS)/$(SRC_FILES)/Random.cpp	\
			$(CORE)/$(SRC_FILES)/APlugin.cpp		\
			$(CORE)/$(SRC_FILES)/Ecosysteme.cpp	\
			$(CORE)/$(SRC_FILES)/PluginManager.cpp

OBJ		=	$(SRC:.cpp=.o)

NAME		=	ecosysteme

RM		=	rm -rf

CC		=	g++

LIBS		=	-I./$(TOOLS)/$(HDR_FILES)		\
			-I./$(CORE)/$(HDR_FILES)		\
			-lSDL -lSDL_image			\
			-lGL -lGLU -ldl				\
			-Wall -Werror -Wextra			\
			-ansi

CXXFLAGS	=	-Wall -Werror -W -Wextra -g3 $(LIBS)

all:			$(NAME)

$(NAME):		$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(LIBS)

clean:
			$(RM) $(OBJ)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

