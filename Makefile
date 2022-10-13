SRCS = main.c \
	   signal/signal.c \
	   libft/*.c \
	   util/*.c \
	   lexer/*.c \
	   shell_grammar/*.c \
	   parsing/*.c \
	   visitor/*.c \
	   execution/*.c \
	   builtins/export.c builtins/echo.c	builtins/env.c builtins/pwd.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

#LDFLAGS = -L /goinfre/$(USER)/.brew/opt/readline/lib
#CPPFLAGS = -I /goinfre/$(USER)/.brew/opt/readline/include

LDFLAGS = -L "/Users/$(USER)/.brew/opt/readline/lib"
CPPFLAGS = -I "/Users/$(USER)/.brew/opt/readline/include"

NAME = minishell

$(NAME) :
		@$(CC) $(CFLAGS) -lreadline $(LDFLAGS) $(CPPFLAGS) -o $(NAME) $(SRCS)
		@stty -echoctl
		@echo "\033[0;32m the library is perfectly constructed\033[0;37m"

all : $(NAME)

clean :
		@rm -f $(OBJS)
		@echo "\033[0;31m the .o files deleted\033[0;37m"

fclean : clean
		@rm -f $(NAME)
		@echo "\033[0;31m the library is perfectly deconstructed\033[0;37m"

re : fclean all

.PHONY : all clean fclean re