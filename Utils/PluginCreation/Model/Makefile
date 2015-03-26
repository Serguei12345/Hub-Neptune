##		PluginName

SRC_FILES	=	sources

HDR_FILES	=	headers

SRC		=	$(SRC_FILES)/ClassName.cpp

OBJ		=	$(SRC:.cpp=.o)

CC		=	g++

RM		=	rm -rf

CXXFLAGS	=	-Wall -Werror -Wextra		\
			-fPIC				\
			-ansi				\
			-I./$(HDR_FILES)		\
			-lSDL -lSDL_image		\
			-lGL -lGLU -ldl

NAME		=	PluginName.so

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -shared -o $(NAME) $(OBJ) $(LIBS)
		mv $(NAME) ../../../Plugins

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
