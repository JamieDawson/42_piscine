# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jadawson <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/01 19:54:59 by jadawson          #+#    #+#              #
#    Updated: 2017/11/01 20:13:17 by jadawson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

gcc -Wall -Wextra -Werror -c ft_swap.c ft_putchar.c ft_strlen.c ft_strcmp.c ft_putstr.c
ar rc libft.a ft_putchar.o ft_swap.o ft_strlen.o ft_strcmp.o ft_putstr.o
rm *.o
