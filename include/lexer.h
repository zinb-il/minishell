/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 12:17:32 by ziloughm          #+#    #+#             */
/*   Updated: 2022/08/25 19:23:07 by ziloughm         ###   ########.fr       */
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
int		check_spcl_char(char *str, char *c, int i);
t_token	*lexer_get_next_token(t_lexer *lexer);
t_token	*lexer_collect_string(t_lexer *lexer);
t_token	*lexer_collect_pipe(t_lexer *lexer);
t_token	*lexer_collect_and(t_lexer *lexer);
t_token	*lexer_collect_great(t_lexer *lexer);
t_token	*lexer_collect_less(t_lexer *lexer);
t_token	*lexer_collect_minishell(t_lexer *lexer);
t_token	*lexer_collect_id(t_lexer *lexer);
char	*lexer_collect_single_quote(t_lexer *lexer);
char	*lexer_simple_caraters(t_lexer *lexer);
void	lexer(char *str);
#		endif