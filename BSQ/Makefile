# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apuel <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 13:02:32 by apuel             #+#    #+#              #
#    Updated: 2017/11/12 20:15:16 by apuel            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			:=	gcc

TARGET		:=	bsq

CFLAGS		:=	-Wall -Wextra -Werror -o $(TARGET)
CFILES		:=	$(wildcard *.c)

all: $(TARGET)

$(TARGET):
		$(CC) $(CFLAGS) $(CFILES)

clean:
		rm -f $(wildcard *.o)

fclean: clean
		rm -f $(TARGET)

re: fclean all
