SRC_DIR		=	src/

INC_DIR		=	include/

SRC		=	$(SRC_DIR)main.c	\
			$(SRC_DIR)explode.c	\
			$(SRC_DIR)usage.c	\
			$(SRC_DIR)parse_options.c	\
			$(SRC_DIR)add_watched_files.c	\
			$(SRC_DIR)run_livereload.c	\
			$(SRC_DIR)exec_command.c

OBJ		=	$(SRC:.c=.o)

CFLAGS		+=	-W -Wall -Wextra	\
			-I $(INC_DIR)	\
			-O3

NAME		=	livereload

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

install:	re
		sudo cp $(NAME) /usr/bin/
		@make fclean --no-print-directory

clean:
		@$(RM) $(OBJ)

fclean:		clean
		@$(RM) $(NAME)

re:		fclean all

.PHONY:		all install clean fclean re
