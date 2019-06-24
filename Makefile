NAME = fillit

SRC_DIR = srcs
OBJ_DIR	= objs
LIB_DIR = libft

SRCS =	main.c \
			dlx_list.c \
			error.c \
			top_left.c \
			resolver.c \
			checker.c \
			cleaner.c

OBJS = $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

L_FT = $(LIB_DIR)/libft

INCLUDES = libft

FLAGS = -Wall -Wextra -Werror

all:
	mkdir -p $(OBJ_DIR)
	@$(MAKE) -C $(L_FT) --no-print-directory
	@$(MAKE) $(NAME) --no-print-directory

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(LIB_INC) -I $(INC_DIR) -o $@ -c $<

$(NAME): $(OBJS)
	gcc -I $(LIB_DIR) $(FLAGS) $(OBJS) $(LIB_DIR)/libft.a -o $(NAME)

bin:
	gcc $(FLAGS) $(TEST)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all