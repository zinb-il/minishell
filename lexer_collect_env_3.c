/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_collect_env_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:13:17 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/19 17:45:11 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*lexer_collect_quote_inouput_quotes(t_lexer *lexer, char c)
{
	t_token	*token;

	if (!check_close_quote(lexer->content, c, lexer->i + 1))
		token = init_token(TOKEN_ERR, ft_strjoin("Unclosed quote near ", \
		lexer->content + lexer->i));
	else
		token = lexer_collect_quotes_ouinput(lexer, c);
	return (token);
}

t_token	*lexer_collect_quotes_ouinput(t_lexer *lexer, char c)
{
	t_token	*token;
	char	*str;
	char	*str1;

	str = get_inouput_str(lexer, c);
	if (lexer->c == '$')
		token = lexer_collect_env_out_int(lexer, "$");
	else if (lexer->c == '"')
		token = lexer_collect_quote_inouput_quotes(lexer, '"');
	else if (lexer->c == '\'')
		token = lexer_collect_quote_inouput_quotes(lexer, '\'');
	else if (!check_spcl_char(SPCL, lexer->c))
		token = lexer_collect_env_herdoc(lexer, "");
	else
		token = init_token(TOKEN_WORD_EX, ft_strdup(""));
	if (token->type != TOKEN_ERR)
	{
		str1 = token->value;
		token->type = TOKEN_WORD_EX;
		token->value = ft_strjoin(str, token->value);
		free(str1);
	}
	free(str);
	return (token);
}

t_token	*lexer_collect_env_inout_quotes(t_lexer *lexer, char *str, char c)
{
	t_token	*token;
	char	*str1;

	if (c == '$')
		token = lexer_collect_env_out_int(lexer, "$");
	else
	{
		if (!check_close_quote(lexer->content, c, lexer->i + 1))
			token = init_token(TOKEN_ERR, ft_strjoin("Unclosed quote near ", \
			lexer->content + lexer->i));
		else
			token = lexer_collect_quotes_ouinput(lexer, lexer->c);
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

t_token	*lexer_collect_env_out_int(t_lexer *lexer, char	*s)
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
		return (lexer_collect_env_inout_quotes(lexer, str, lexer->c));
	return (init_token(TOKEN_WORD, str));
}
