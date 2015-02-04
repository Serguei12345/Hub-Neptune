##
## Makefile for ecosysteme in /home/ovoyan_s/rendu/ECOSYSTEME
## 
## Made by ovoyan_s
## Login   <ovoyan_s@epitech.net>
## 
## Started on  Wed Apr 30 16:52:06 2014 ovoyan_s
## Last update Wed Feb  4 17:09:41 2015 ovoyan_s
##

SRC_FILES	=	sources

HDR_FILES	=	headers

TOOLS		=	Tools

SRC		=	main.cpp 				\
			$(TOOLS)/$(SRC_FILES)/FileManager.cpp

OBJ		=	$(SRC:.cpp=.o)

NAME		=	ecosysteme

RM		=	rm -rf

CC		=	g++

LIBS		=	-I./$(TOOLS)/$(HDR_FILES)		\
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

