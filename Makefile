##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC_DIR		=	src/

INC_DIR		=	include/

SRC		=	$(SRC_DIR)main.c

OBJ		=	$(SRC:.c=.o)

CFLAGS		+=	-W -Wall -Wextra	\
			-I $(INC_DIR)	\
			-Og

NAME		=	c_live_reload

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ)

clean:
		@rm -f $(OBJ)

fclean:		clean
		@rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
