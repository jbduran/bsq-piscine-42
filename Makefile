# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjacquem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/28 14:00:05 by cjacquem          #+#    #+#              #
#    Updated: 2015/07/28 18:32:42 by cjacquem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRC = ./srcs/main.c\
	  ./srcs/functions.c\
	  ./srcs/ft_read_file.c\
	  ./srcs/solve.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all: $(NAME)

$(NAME): .o .a

.o:
	@$(CC) $(FLAGS) -c $(SRCS)

.a: .o
	@$(CC) $(FLAGS) $(OBJ) -I includes -o $(NAME)

clean:
	@$(RM) *.o

fclean: clean
	@$(RM) $(NAME)

re: fclean all
