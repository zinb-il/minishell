/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_collect_double_quote_1.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 19:17:25 by ziloughm          #+#    #+#             */
/*   Updated: 2022/09/27 13:55:46 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*lexer_collect_double_quote_env_dollar(t_lexer *lexer)
{
	char	*str;

	str = 0;
	if (lexer->c == '?')
	{
		str = ft_itoa(g_vars.exit_code);
		lexer_advance(&lexer);
	}
	else if (lexer->c == '$')
	{
		str = ft_itoa(g_vars.child_process_pid);
		lexer_advance(&lexer);
	}
	return (str);
}

char	*lexer_collect_double_quote_env(t_lexer *lexer)
{
	char	*str;
	char	*str1;
	char	c;

	lexer_advance(&lexer);
	c = lexer->c;
	if (lexer->c == '?' || lexer->c == '$')
		str = lexer_collect_double_quote_env_dollar(lexer);
	else if (lexer->c == '"')
		str = ft_strdup("$");
	else
		str = lexer_collect_env_val(lexer);
	if (!(int)ft_strlen(str) && !ft_isalnum(c) && c != '_')
	{
		str1 = str;
		str = ft_strjoin("$", str);
		free(str1);
	}
	return (str);
}

char	*lexer_collect_double_quote_char(t_lexer *lexer, char c)
{
	char	*str1;

	lexer_advance(&lexer);
	str1 = (char *)malloc(2 * sizeof(char));
	if (!str1)
		return (str1);
	str1[0] = c;
	str1[1] = 0;
	return (str1);
}

t_token	*lexer_collect_double_quote_after(t_lexer *lexer, char *str, char c)
{
	t_token	*token;
	char	*s;

	if (c == '$')
		token = lexer_collect_env(lexer);
	else if (c == '\'')
		token = lexer_collect_single_quote(lexer);
	else if (c == '"')
		token = lexer_collect_double_quote(lexer);
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

t_token	*lexer_collect_double_quote(t_lexer *lexer)
{
	char	*str2;
	char	*str3;
	char	*str1;

	if (!check_close_quote(lexer->content, '"', lexer->i + 1))
		return (init_token(TOKEN_ERR, ft_strjoin("Unclosed quote near ", \
		lexer->content + lexer->i)));
	if (check_herdoc(lexer))
		return (lexer_collect_double_quote_herdoc(lexer));
	lexer_advance(&lexer);
	str2 = ft_strdup("");
	while (lexer->c != '\0' && lexer->c != '"')
	{
		if (lexer->c == '$' && lexer->content[lexer->i - 1] != '\\')
			str1 = lexer_collect_double_quote_env(lexer);
		else
			str1 = lexer_collect_double_quote_char(lexer, lexer->c);
		str3 = str2;
		str2 = ft_strjoin(str2, str1);
		free(str3);
		free(str1);
	}
	lexer_advance(&lexer);
	return (lexer_collect_double_quote_fafter(lexer, str2));
}
