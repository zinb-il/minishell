/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_collect_double_quote.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 19:17:25 by ziloughm          #+#    #+#             */
/*   Updated: 2022/09/15 21:44:52 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*lexer_collect_double_quote_env(t_lexer *lexer)
{
	lexer_advance(&lexer);
	return (lexer_collect_env_val(lexer));
}

char	*lexer_collect_double_quote_char(t_lexer *lexer, char c)
{
	char	*str1;

	str1 = ft_strdup(&c);
	lexer_advance(&lexer);
	return (str1);
}

t_token	*lexer_collect_double_quote_after(t_lexer *lexer, char *str, char c)
{
	t_token	*token;
	char	*s;

	if (c == '$')
		token = lexer_collect_env(lexer);
	if (c == '\'')
		token = lexer_collect_single_quote(lexer);
	else
		token = lexer_simple_caraters(lexer);
	if (token->type != TOKEN_ERR)
	{
		s = token->value;
		token->value = ft_strjoin(str, token->value);
		free(s);
	}
	free(str);
	return (token);
}

t_token	*lexer_collect_double_quote(t_lexer *lexer)
{
	char	*str2;
	char	*str3;
	char	*str1;

	lexer_advance(&lexer);
	if (!check_close_quote(lexer->content, '"', lexer->i))
		return (init_token(TOKEN_ERR, ft_strjoin("Unclosed quote near ", \
		lexer->content + lexer->i - 1)));
	str2 = ft_strdup("");
	while (lexer->c != '\0' && lexer->c != '"')
	{
		str3 = str2;
		if (lexer->c == '$' && lexer->content[lexer->i - 1] != '\\')
			str1 = lexer_collect_double_quote_env(lexer);
		else
			str1 = lexer_collect_double_quote_char(lexer, lexer->c);
		str2 = ft_strjoin(str2, str1);
		free(str3);
		free(str1);
	}
	lexer_advance(&lexer);
	/*if (lexer->c == '$' || !check_spcl_char(SPCL, lexer->c) || lexer->c == '\'')
		return (lexer_collect_double_quote_after(lexer, str1, lexer->c));*/
	return (init_token(TOKEN_WORD, str2));
}
