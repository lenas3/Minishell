NAME = minishell

SRCS = main.c \
		parser/lexer_utils.c \
		parser/lexer.c \
		parser/utils.c \
		parser/clean.c \
		parser/init.c
OBJS = $(SRCS:.c=.o)

INCLUDES = -I include
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -lreadline -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re