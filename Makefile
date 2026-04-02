NAME	= push_swap

CC		= cc
CFLAGS	= -Wall -Werror -Wextra -I include -g

SRC_DIR	= src

SRCS	=	main.c \
			parsing.c \
			operations.c \
			sort.c \
			validation.c \
			str_utils.c \
			utils.c

OBJS	= $(addprefix $(SRC_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
