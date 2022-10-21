/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_collect_env_4.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:02:57 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/20 17:53:19 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*lexer_collect_env_parenth_io_after(t_lexer *lexer, char *str, char c)
{
	t_token	*token;
	char	*str1;

	if (lexer->c == '$')
		token = lexer_collect_env_parenth_inout(lexer);
	else if (lexer->c == '\'')
		token = lexer_collect_quotes_ouinput(lexer, '"');
	else if (lexer->c == '"')
		token = lexer_collect_quotes_ouinput(lexer, '"');
	else
		token = init_token(TOKEN_WORD, ft_strdup(""));
	if (token->type != TOKEN_ERR)
	{
		str1 = token->value;
		if (c != '$')
			token->type = TOKEN_WORD_EX;
		token->value = ft_strjoin(str, token->value);
		if (token->value)
		{
			free(str1);
		}
	}
	free(str);
	return (token);
}

t_token	*lexer_collect_env_parenth_inout(t_lexer *lexer)
{
	char	*str;
	char	*str1;
	int		start;
	int		p;

	start = lexer->i;
	p = 1;
	lexer_advance(&lexer);
	while (lexer->c != '\0' && p)
	{
		if (lexer->c == '(')
			p++;
		if (lexer->c == ')')
			p--;
		lexer_advance(&lexer);
	}
	str = ft_substr(lexer->content, start, lexer->i - start);
	str1 = ft_strjoin("$", str);
	free(str);
	if (lexer->c == '\'' || lexer->c == '"' || lexer->c == '$')
		return (lexer_collect_env_parenth_io_after(lexer, str1, lexer->c));
	return (init_token(TOKEN_WORD, str1));
}

t_token	*lexer_collect_env_parenth_her_after(t_lexer *lexer, char *str, char c)
{
	t_token	*token;
	char	*str1;

	if (lexer->c == '$')
		token = lexer_collect_env_herdoc(lexer, "$");
	else if (lexer->c == '\'')
		token = lexer_collect_quotes_herdoc(lexer, '\'');
	else if (lexer->c == '"')
		token = lexer_collect_quotes_herdoc(lexer, '"');
	else
		token = init_token(TOKEN_WORD, ft_strdup(""));
	if (token->type != TOKEN_ERR)
	{
		str1 = token->value;
		printf("str %s val %s\n", str, str1);
		if (c != '$')
			token->type = TOKEN_WORD_EX;
		token->value = ft_strjoin(str, token->value);
		if (token->value)
		{
			free(str1);
		}
	}
	free(str);
	return (token);
}

t_token	*lexer_collect_env_parenth_herdoc(t_lexer *lexer)
{
	char	*str;
	char	*str1;
	int		start;
	int		p;

	start = lexer->i;
	p = 1;
	lexer_advance(&lexer);
	while (lexer->c != '\0' && p)
	{
		if (lexer->c == '(')
			p++;
		if (lexer->c == ')')
			p--;
		lexer_advance(&lexer);
	}
	str = ft_substr(lexer->content, start, lexer->i - start);
	str1 = ft_strjoin("$", str);
	free(str);
	if (lexer->c == '\'' || lexer->c == '"' || lexer->c == '$')
		return (lexer_collect_env_parenth_her_after(lexer, str1, lexer->c));
	return (init_token(TOKEN_WORD, str1));
}

t_token	*lexer_collect_env_onedol_quotes(t_lexer *lexer, char *str)
{
	t_token	*token;
	char	*str1;

	if (lexer->c == '\'')
		token = lexer_collect_single_quote(lexer);
	else if (lexer->c == '"')
		token = lexer_collect_double_quote(lexer);
	else
		token = init_token(TOKEN_WORD, ft_strdup(""));
	if (token->type != TOKEN_ERR)
	{
		str1 = token->value;
		token->value = ft_strjoin(str, token->value);
		free(str1);
	}
	free(str);
	return (token);
}
