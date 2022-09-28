/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_collect_env_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 17:31:51 by ziloughm          #+#    #+#             */
/*   Updated: 2022/09/27 18:13:55 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_token	*lexer_collect_env_herdoc_quotes(t_lexer *lexer, char *str, char c)
{
	t_token	*token;
	char	*str1;

	if (c == '$')
		token = lexer_collect_env_herdoc(lexer, "$");
	else
	{
		if (!check_close_quote(lexer->content, c, lexer->i + 1))
			token = init_token(TOKEN_ERR, ft_strjoin("Unclosed quote near ", \
			lexer->content + lexer->i));
		else
			token = lexer_collect_quotes_herdoc(lexer, lexer->c);
	}
	if (token->type != TOKEN_ERR)
	{
		str1 = token->value;
		if (c != '$')
			token->type = TOKEN_WORD_EX;
		token->value = ft_strjoin(str, token->value);
		free(str1);
	}
	free(str);
	return (token);
}

t_token	*lexer_collect_env_and(t_lexer *lexer)
{
	char	*str;
	char	*s;
	t_token	*token;

	if (lexer->content[lexer->i + 1] == '\0')
		return (advs_token(lexer, init_token(TOKEN_WORD, ft_strdup("$&"))));
	str = lexer_after_single_and(lexer, ft_strdup("$"));
	if (lexer->c == '$')
		token = lexer_collect_env(lexer);
	else if (lexer->c == '\'')
		token = lexer_collect_single_quote(lexer);
	else if (lexer->c == '"')
		token = lexer_collect_double_quote(lexer);
	else
		token = init_token(TOKEN_WORD, ft_strdup(""));
	if (token->type != TOKEN_ERR)
	{
		s = token->value;
		token->value = ft_strjoin(str, token->value);
		free(str);
		free(s);
	}
	return (token);
}

t_token	*lexer_collect_env_parenth(t_lexer *lexer)
{
	char	*str;
	char	*str1;
	char	*str2;

	str = (char *)malloc(2 * sizeof(char));
	str[1] = 0;
	str1 = ft_strdup("$");
	while ((lexer->c != '\0' && !check_spcl_char(SPCL2, lexer->c)) || \
	(lexer->c == '&' && lexer->content[lexer->i + 1] != '&'))
	{
		str[0] = lexer->c;
		str2 = str1;
		str1 = ft_strjoin(str1, str);
		free(str2);
		lexer_advance(&lexer);
	}
	free(str);
	return (init_token(TOKEN_WORD, str1));
}

t_token	*lexer_collect_env_herdoc(t_lexer *lexer, char	*s)
{
	char	*str;
	char	*str1;
	int		i;

	if (ft_strlen(s))
	{
		lexer_advance(&lexer);
		if (lexer->c == '(')
			return (lexer_collect_env_parenth(lexer));
		if (lexer->c == '&' && (!lexer->content[lexer->i + 1] || \
		lexer->content[lexer->i + 1] != '&'))
			return (lexer_collect_env_and(lexer));
	}
	i = lexer->i;
	while (!check_spcl_char(SPCL3, lexer->c) && lexer->c != '\0')
		lexer_advance(&lexer);
	str = ft_substr(lexer->content, i, lexer->i - i);
	str1 = str;
	str = ft_strjoin(s, str);
	free(str1);
	if (lexer->c == '\'' || lexer->c == '"' || lexer->c == '$')
		return (lexer_collect_env_herdoc_quotes(lexer, str, lexer->c));
	return (init_token(TOKEN_WORD, str));
}
