# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jadawson <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/06 11:27:42 by jadawson          #+#    #+#              #
#    Updated: 2017/11/06 14:14:48 by jadawson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c

HEADER = includes

FLAGS = -c -Wall -Wextra -Werror -I$(HEADER)

NAME = libft.a

CC = gcc

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRCS)
	ar rc $(NAME) ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o
	ar -t $(NAME)
clean:
	rm -f ft_putchar.o ft_putstr.o ft_strlen.o ft_swap.o ft_strcmp.o
fclean: clean
	rm -f $(NAME)
re: fclean all
