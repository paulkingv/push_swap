# this makefile has been validated 13 April 2026
NAME	= push_swap

CC		= cc
CFLAGS	= -Wall -Werror -Wextra -I include -g

SRC_DIR	= src

SRCS	=	main.c \
			parsing_argv.c \
			operations.c \
			sorting.c \
			validation.c \
			indexing.c \
			utils.c

OBJS	= $(addprefix $(SRC_DIR)/, $(SRCS:.c=.o))

LIBFT_DIR = include/libft
LIBFT_NAME = libft.a
LIBFT_PATH = $(LIBFT_DIR)/$(LIBFT_NAME)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_PATH)
	@echo "Linking Libft..."
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I include -I$(LIBFT_DIR) -c $< -o $@

$(LIBFT_PATH):
	@echo "Building libft..."
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
