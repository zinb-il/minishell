/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_collect_single_quote_1.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:30:15 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/19 17:49:24 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*lexer_collect_single_quote_env_smp(t_lexer *lexer, char *str, char c)
{
	t_token	*token;
	char	*s;

	if (c == '$')
		token = lexer_collect_env(lexer);
	else if (c == '"')
		token = lexer_collect_double_quote(lexer);
	else if (c == '\'')
		token = lexer_collect_single_quote(lexer);
	else
		token = lexer_simple_caraters(lexer);
	if (token->type != TOKEN_ERR)
	{
		s = token->value;
		token->type = TOKEN_WORD_EX;
		token->value = ft_strjoin(str, token->value);
		free(s);
	}
	free(str);
	return (token);
}

t_token	*lexer_collect_single_quote(t_lexer *lexer)
{
	char	*str1;
	int		start;

	if (!check_close_quote(lexer->content, '\'', lexer->i + 1))
		return (init_token(TOKEN_ERR, ft_strjoin("Unclosed quote near ", \
		lexer->content + lexer->i)));
	if (check_herdoc(lexer))
		return (lexer_collect_quotes_herdoc(lexer, '\''));
	if (check_in_out_put(lexer))
		return (lexer_collect_quotes_ouinput(lexer, '\''));
	lexer_advance(&lexer);
	start = lexer->i;
	while (lexer->c != '\0' && lexer->c != '\'')
		lexer_advance(&lexer);
	str1 = ft_substr(lexer->content, start, lexer->i - start);
	lexer_advance(&lexer);
	if (lexer->c == '&' && lexer->content[lexer->i + 1] != '&')
		str1 = lexer_after_single_and(lexer, str1);
	if (lexer->c == '$' || !check_spcl_char(SPCL, lexer->c) || lexer->c == '"' \
	|| lexer->c == '\'')
		return (lexer_collect_single_quote_env_smp(lexer, str1, lexer->c));
	return (init_token(TOKEN_WORD_EX, str1));
}
