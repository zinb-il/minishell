/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 12:17:32 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/05 10:55:58 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef LEXER_H
# define LEXER_H

typedef struct s_lexer
{
	char	c;
	int		i;
	char	*content;
}t_lexer;

t_lexer	*init_lexer(char	*content);
void	lexer_advance(t_lexer **lexer);
void	lexer_skipe_space(t_lexer *lexer);
char	*lexer_char_to_string(t_lexer *lexer);
t_token	*advs_token(t_lexer *lexer, t_token *token);
int		check_close_quote(char *str, char c, int i);
void	get_new_str(char *str);
int		check_close_parenthesis(char *str);
int		check_spcl_char(char *str, char c);
int		check_herdoc(t_lexer *lexer);
char	*get_herdoc_str(t_lexer *lexer, char c);
char	*lexer_after_single_and(t_lexer *lexer, char *str1);
int		check_herdoc(t_lexer *lexer);
t_token	*lexer_get_next_token(t_lexer *lexer);
t_token	*lexer_collect_pipe(t_lexer *lexer);
t_token	*lexer_collect_and(t_lexer *lexer);
t_token	*lexer_collect_great(t_lexer *lexer);
t_token	*lexer_collect_less(t_lexer *lexer);
t_token	*lexer_collect_minishell(t_lexer *lexer);
t_token	*lexer_collect_id(t_lexer *lexer);

//GET word inside single quote
char	*lexer_collect_env_val(t_lexer *lexer);
t_token	*lexer_collect_single_quote(t_lexer *lexer);
t_token	*lexer_collect_single_quote_env_smp(t_lexer *lexer, char *str, char c);

//GET word inside double quote
t_token	*lexer_collect_double_quote(t_lexer *lexer);
char	*lexer_collect_double_quote_env(t_lexer *lexer);
t_token	*lexer_collect_double_quote_after(t_lexer *lexer, char *str, char c);
t_token	*lexer_collect_double_quote_fafter(t_lexer *lexer, char *str2);
t_token	*lexer_collect_quote_herdoc_quotes(t_lexer *lexer, char c);
t_token	*lexer_collect_quotes_herdoc(t_lexer *lexer, char c);
char	*lexer_collect_double_quote_char(t_lexer *lexer, char c);

//GET expanded word
char	*add_dollar_or_not(char *str, int i);
char	*lexer_collect_double_quote_env_dollar(t_lexer *lexer);
t_token	*lexer_collect_env_str_quote(t_lexer *lexer, char *str, char c, int i);
t_token	*lexer_collect_dollar(t_lexer *lexer);
t_token	*lexer_collect_env_str(t_lexer *lexer);
t_token	*lexer_collect_env_herdoc_quotes(t_lexer *lexer, char *str, char c);
t_token	*lexer_collect_env_and(t_lexer *lexer);
t_token	*lexer_collect_env_parenth(t_lexer *lexer);
t_token	*lexer_collect_env_herdoc(t_lexer *lexer, char	*s);
t_token	*lexer_collect_env(t_lexer *lexer);

//GET simple Word
t_token	*lexer_simple_caraters(t_lexer *lexer);
t_token	*lexer_simple_caraters_env_quote(t_lexer *lexer, char *str, char c);

//GET parenthesis
t_token	*lexer_collect_parenthesis(t_lexer *lexer);

//Free the Lexer , Tokens , AST
void	free_lexer(t_lexer *lex);

//Create list of tokens 
t_token	*get_tokens(t_lexer lexer);

//Lexer function
t_token	*lexer(char *str);

#		endif