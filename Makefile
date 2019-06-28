# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmarin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/25 20:31:28 by gmarin            #+#    #+#              #
#    Updated: 2019/06/25 20:31:51 by gmarin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC_DIR = ./srcs
LIB_DIR = ./libft

SRC_FILES =	main.c \
			dlx_list.c \
			top_left.c \
			resolver.c \
			checker.c \
			cleaner.c \
			error.c

SRCS = $(addprefix $(SRC_DIR)/,$(SRC_FILES))
OBJS = $(SRC_FILES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -I$(LIB_DIR) -I$(SRC_DIR)

all: $(NAME)

bin:
	@$(CC) $(CFLAGS) $(LFLAGS) -c $(SRCS)

$(NAME): lib bin
	@$(CC) $(CFLAGS) $(LFLAGS) $(OBJS) -L$(LIB_DIR) -lft -o $(NAME)

lib:
	@make -C $(LIB_DIR)

clean:
	@rm -rf $(OBJS)
	@make -C $(LIB_DIR) clean

fclean:
	@rm -rf $(OBJS) $(NAME)
	@make -C $(LIB_DIR) fclean

re: fclean $(NAME)
