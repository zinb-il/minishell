SRCS = ast_1.c ast_2.c ast_3.c cd.c cmd.c delete_env.c echo.c env.c execute_bl.c execute_cmd_line.c execution_1.c execution_util_1.c execution_util_2.c execution_util_3.c execution_util_4.c exit.c export.c \
	   export_util.c export_util_1.c first_part.c ft_atoi.c ft_bzero.c ft_calloc.c ft_fndc.c ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_itoa.c ft_lstadd_back.c ft_lstadd_front.c ft_lstlast.c ft_lstnew.c ft_lstsize.c \
	   ft_lstsize_tcmd.c ft_lstsizecmd.c ft_putchar_fd.c ft_putstr_fd.c ft_split.c ft_strcmp.c ft_strdup.c ft_strdup_d.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strncmp.c ft_strrchr.c ft_strrrchr.c ft_strsize.c \
       ft_substr.c ft_tolower.c get_env.c init_minishell.c lexer.c lexer_collect_double_quote_1.c lexer_collect_double_quote_2.c lexer_collect_env_1.c lexer_collect_env_2.c lexer_collect_id.c lexer_collect_meta.c \
       lexer_collect_parenthesis.c lexer_collect_single_quote_1.c lexer_simple_caraters.c lexer_token_ast_free_1.c lexer_token_ast_free_2.c lexer_utile_1.c lexer_utile_2.c lexer_utile_3.c main.c new_prompt.c node_1.c \
       node_2.c node_3.c pwd.c scan_grammar_1.c scan_grammar_2.c signal.c token.c unlink_herdocfiles.c unset.c visitor_creat_output_file.c visitor_herdoc_1.c visitor_herdoc_2.c visitor_wildcards_1.c visitor_wildcards_2.c


OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

LDFLAGS = -L "/Users/$(USER)/.brew/opt/readline/lib"
CPPFLAGS = -I "/Users/$(USER)/.brew/opt/readline/include"

#LDFLAGS = -L /goinfre/$(USER)/.brew/opt/readline/lib
#CPPFLAGS = -I /goinfre/$(USER)/.brew/opt/readline/include

#CFLAGS = -Wall -Wextra -Werror 

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