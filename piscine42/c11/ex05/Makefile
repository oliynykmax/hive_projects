# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maoliiny <maoliiny@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/12 22:12:08 by maoliiny          #+#    #+#              #
#    Updated: 2025/03/12 22:17:39 by maoliiny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
NAME	= do-op

# Source files and object files
SRCS	= ft_atoi.c main.c
OBJS	= $(SRCS:.c=.o)

# Build rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rules
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
