SRC_DIR		=	src/

INC_DIR		=	include/

SRC		=	$(SRC_DIR)main.c	\
			$(SRC_DIR)explode.c	\
			$(SRC_DIR)usage.c	\
			$(SRC_DIR)parse_options.c	\
			$(SRC_DIR)add_watched_files.c	\
			$(SRC_DIR)run_livereload.c	\
			$(SRC_DIR)compile.c	\
			$(SRC_DIR)execute.c

OBJ		=	$(SRC:.c=.o)

CFLAGS		+=	-W -Wall -Wextra	\
			-I $(INC_DIR)	\
			-Og	\
			-g

NAME		=	c_livereload

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ)
		cp $(NAME) ../lol

clean:
		@rm -f $(OBJ)

fclean:		clean
		@rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
