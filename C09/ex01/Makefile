# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/11 12:01:46 by aramos-e          #+#    #+#              #
#    Updated: 2026/02/12 11:28:48 by aramos-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS_DIR = srcs
INCS_DIR = includes

SRCS = $(SRCS_DIR)/ft_putchar.c \
       $(SRCS_DIR)/ft_swap.c \
       $(SRCS_DIR)/ft_putstr.c \
       $(SRCS_DIR)/ft_strlen.c \
       $(SRCS_DIR)/ft_strcmp.c

OBJS = $(SRCS:.c=.o)

INCS = -I $(INCS_DIR)

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar rcs
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re 