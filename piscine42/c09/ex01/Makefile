# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maoliiny <maoliiny@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/06 15:11:09 by maoliiny          #+#    #+#              #
#    Updated: 2025/03/06 15:11:22 by maoliiny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = libft.a

SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c \
	srcs/ft_strcmp.c

OBJS = ${SRCS:.c=.o}

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror
.c.o:
	${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}

$(LIB): ${OBJS}
	ar rcs ${LIB} ${OBJS}


all:	${LIB}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${LIB}

re:		fclean all

.PHONY: all clean fclean re
