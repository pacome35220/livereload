SRC_DIR		=	src/

LIB_DIR		=	lib/

INC_DIR		=	include/

SRC		=	$(SRC_DIR)main.c	\
			$(SRC_DIR)usage.c	\
			$(SRC_DIR)parse_options.c	\
			$(SRC_DIR)add_watched_files.c	\
			$(SRC_DIR)run_livereload.c	\
			$(LIB_DIR)my_str_to_word_array.c

OBJ		=	$(SRC:.c=.o)

CFLAGS		+=	-W -Wall -Wextra	\
			-I $(INC_DIR)	\
			-Og	\
			-g

NAME		=	c_livereload

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ)

clean:
		@rm -f $(OBJ)

fclean:		clean
		@rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
