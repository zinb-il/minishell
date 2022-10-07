/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_simple_caraters.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:21:42 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/06 19:31:18 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_token	*lexer_simple_caraters_env_quote(t_lexer *lexer, char *str, char c)
{
	t_token	*token;
	char	*s;

	if (c == '$')
		token = lexer_collect_env(lexer);
	else if (c == '"')
		token = lexer_collect_double_quote(lexer);
	else
		token = lexer_collect_single_quote(lexer);
	if (token->type != TOKEN_ERR)
	{
		s = token->value;
		token->value = ft_strjoin(str, token->value);
		free(s);
	}
	free(str);
	return (token);
}

t_token	*lexer_simple_caraters(t_lexer *lexer)
{
	char	*str;
	char	*str1;
	int		s;

	if (check_herdoc(lexer))
		return (lexer_collect_env_herdoc(lexer, ""));
	str = ft_strdup(lexer->content);
	s = lexer->i;
	while (lexer->c != '\0' && !check_spcl_char(SPCL, lexer->c))
		lexer_advance(&lexer);
	str1 = ft_substr(str, s, lexer->i - s);
	free (str);
	if (lexer->c == '&' && lexer->content[lexer->i + 1] != '&')
		str1 = lexer_after_single_and(lexer, str1);
	if (lexer->c == '$' || lexer->c == '\'' || lexer->c == '"')
		return (lexer_simple_caraters_env_quote(lexer, str1, lexer->c));
	return (init_token(TOKEN_WORD, str1));
}
