# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabdali <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 10:45:53 by mabdali           #+#    #+#              #
#    Updated: 2023/03/13 14:13:57 by mabdali          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SERVER_SRC  =   ft_server.c

SERVER_OBJS =   $(SERVER_SRC:.c=.o)

CLIENT_SRC  =	ft_client.c \
				ft_client_utils.c \
				get_next_line.c \
				get_next_line_utils.c

CLIENT_OBJS =   $(CLIENT_SRC:.c=.o)

OBJS        =   $(CLIENT_OBJS) \
                $(SERVER_OBJS)

NAME = server

SERVER_NAME = server

CLIENT_NAME = client

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : ft_server ft_client

ft_server : $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(SERVER_OBJS) libftprintf.a -o server

ft_client : $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) libftprintf.a -o client

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf server client

re: fclean all

.PHONY: all ft_client ft_server clean fclean re

