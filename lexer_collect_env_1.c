/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_collect_env_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 19:44:16 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/23 18:15:53 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*lexer_collect_env_val(t_lexer *lexer)
{
	int		start;
	char	*str1;
	char	*str2;

	start = lexer->i;
	while (ft_isalnum(lexer->c) || lexer->c == '_')
		lexer_advance(&lexer);
	str1 = ft_substr(lexer->content, start, lexer->i - start);
	str2 = get_env_val(g_vars.env, str1);
	free(str1);
	return (str2);
}

t_token	*lexer_collect_env_str_quote(t_lexer *lexer, char *str, char c, int i)
{
	t_token	*token;
	char	*s;

	if (c == '\'')
		token = lexer_collect_single_quote(lexer);
	else if (c == '"')
		token = lexer_collect_double_quote(lexer);
	else if (c == '$')
		token = lexer_collect_env(lexer);
	else
	{
		token = lexer_simple_caraters(lexer);
		token->value = add_dollar_or_not(token->value, i);
	}
	if (token->type != TOKEN_ERR)
	{
		s = token->value;
		token->value = ft_strjoin(str, token->value);
		free(s);
	}
	free(str);
	return (token);
}

t_token	*lexer_collect_dollar(t_lexer *lexer)
{
	char	*str;

	if (lexer->c == '?')
		str = ft_itoa(env_expand_exit_code(lexer->i, lexer->content));
	if (lexer->c == '$')
		str = ft_strdup("$$");
	lexer_advance(&lexer);
	if (lexer->c == '&' && lexer->content[lexer->i + 1] != '&')
		str = lexer_after_single_and(lexer, str);
	if ((lexer->c == '\'' || lexer->c == '"' || lexer->c == '$' \
	|| !check_spcl_char(SPCL1, lexer->c)) && lexer->c != '\0')
		return (lexer_collect_env_str_quote(lexer, str, \
		lexer->c, (int)ft_strlen(str)));
	return (init_token(TOKEN_WORD, str));
}

t_token	*lexer_collect_env_str(t_lexer *lexer)
{
	char	*str;
	char	c;
	int		i;

	c = lexer->c;
	i = 1;
	str = lexer_collect_env_val(lexer);
	if (!(int)ft_strlen(str) && !ft_isalnum(c) && c != '_')
		i = 0;
	if ((lexer->c == '\'' || lexer->c == '"' || lexer->c == '$' \
	|| !check_spcl_char(SPCL1, lexer->c)) && lexer->c != '\0')
		return (lexer_collect_env_str_quote(lexer, str, lexer->c, i));
	return (init_token(TOKEN_WORD, str));
}

t_token	*lexer_collect_env(t_lexer *lexer)
{
	if (check_herdoc(lexer))
		return (lexer_collect_env_herdoc(lexer, "$"));
	if (check_in_out_put(lexer))
		return (lexer_collect_env_out_int(lexer, "$"));
	lexer_advance(&lexer);
	if (lexer->c == '?' || lexer->c == '$')
		return (lexer_collect_dollar(lexer));
	else if (lexer->c == '&' && (!lexer->content[lexer->i + 1] || \
	lexer->content[lexer->i + 1] != '&'))
		return (lexer_collect_env_and(lexer));
	else if (lexer->c == '(')
		return (lexer_collect_env_parenth(lexer));
	else if (lexer->c == '"' || lexer->c == '\'')
		return (lexer_collect_env_onedol_quotes(lexer, ft_strdup("$")));
	else if (check_spcl_char(SPCL, lexer->c))
		return (init_token(TOKEN_WORD, ft_strdup("$")));
	else if (lexer->c != '\0')
		return (lexer_collect_env_str(lexer));
	else
		return (init_token(TOKEN_WORD, ft_strdup("$")));
}
