# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maoliiny <maoliiny@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/15 11:05:26 by maoliiny          #+#    #+#              #
#    Updated: 2025/04/28 14:22:58 by maoliiny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_utils.c

OBJS = ${SRCS:.c=.o}
.SECONDARY: ${OBJS}

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): ${OBJS}
	ar rcs ${NAME} ${OBJS}

.c.o:
	${CC} ${CFLAGS} -I. -c $< -o ${<:.c=.o}

clean:
	${RM} ${OBJS}
	
fclean:	clean
	${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re bonus


