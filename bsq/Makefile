
NAME = bsq

CC = cc
CFLAGS = -Wall -Wextra -Werror -I.


SRC = main.c \
		file_reader.c \
		reading_map.c \
		validate.c \
		print_things.c \
		auxiliares.c \
		solve_bsq.c 



OBJ = $(SRC:.c=.o)


all: $(NAME)


$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJ)


fclean: clean
	rm -f $(NAME)


re: fclean all


.PHONY: all clean fclean re