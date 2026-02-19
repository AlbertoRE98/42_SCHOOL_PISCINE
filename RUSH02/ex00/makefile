NAME = rush-02

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
       aux_strings.c \
       more_aux.c \
       dictionary.c \
       parsing.c \
       parsing2.c \
	   parsing3.c \
       numbers_to_words.c \
	   number_to_words2.c \
	   number_to_words3.c \
	   number_to_words4.c 


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c rush02.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re