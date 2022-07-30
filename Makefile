# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: florianmastorakis <marvin@42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/27 16:51:26 by florianma         #+#    #+#              #
#    Updated: 2021/09/02 16:09:55 by flmastor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/initialisation.c \
	   srcs/utils.c \
	   srcs/algo_500.c \
	   srcs/main.c \
	   srcs/utils1.c \
	   srcs/algo_100.c \
	   srcs/error_gestion.c  \
	   srcs/moove.c \
	   srcs/transfer_stack_b.c \
	   srcs/algo_3.c \
	   srcs/error_gestion2.c \
	   srcs/ft_split.c \
	   srcs/moove_rev_rot.c \
	   srcs/moove_rot.c \


OBJS = ${SRCS:.c=.o}

HEADER	= includes

NAME = push_swap

CC = gcc -g

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all: ${NAME}

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(HEADER) -o $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
