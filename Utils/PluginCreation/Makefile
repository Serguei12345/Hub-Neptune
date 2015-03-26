##
## Makefile for pluginCreation in /home/ovoyan_s/Hub-Neptune/Utils/PluginCreation
## 
## Made by ovoyan_s
## Login   <ovoyan_s@epitech.net>
## 
## Started on  Fri Mar 20 15:45:01 2015 ovoyan_s
## Last update Fri Mar 20 15:48:11 2015 ovoyan_s
##

SRC_FILES	=	sources

HDR_FILES	=	headers

SRC		=	$(SRC_FILES)/main.cpp	\
			$(SRC_FILES)/Time.cpp	\
			$(SRC_FILES)/Random.cpp	\
			$(SRC_FILES)/Containers.cpp	\
			$(SRC_FILES)/File.cpp	\
			$(SRC_FILES)/MyException.cpp	\

OBJ		=	$(SRC:.cpp=.o)

CC		=	g++

RM		=	rm -rf

CXXFLAGS	=	-Wall -Werror -Wextra		\
			-I./$(HDR_FILES)		\

NAME		=	pluginCreation

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
