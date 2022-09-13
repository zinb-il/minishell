/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_collect_id.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:55:16 by ziloughm          #+#    #+#             */
/*   Updated: 2022/09/13 23:13:28 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_token	*lexer_collect_single_quote(t_lexer *lexer)
{
	char	*str;
	char	*str1;
	int		start;

	lexer_advance(&lexer);
	str = ft_strdup(lexer->content);
	if (!check_close_quote(str, '\'', lexer->i))
		return (init_token(TOKEN_ERR, ft_strjoin("Unclosed quote near ", \
		str + lexer->i)));
	start = lexer->i;
	while (lexer->c != '\0' && lexer->c != '\'')
		lexer_advance(&lexer);
	lexer_advance(&lexer);
	str1 = ft_substr(str, start, lexer->i - start);
	free (str);
	return (init_token(TOKEN_WORD, str1));
}

t_token	*lexer_simple_caraters(t_lexer *lexer)
{
	char	*str;
	char	*str1;
	int		s;
	int		e;

	str = ft_strdup(lexer->content);
	s = lexer->i;
	while (lexer->c != '\0' && !check_spcl_char(SPCL, lexer->c))
		lexer_advance(&lexer);
	e = lexer->i;
	str1 = ft_substr(str, s, e);
	free (str);
	return (init_token(TOKEN_WORD, str1));
}

t_token	*lexer_collect_id(t_lexer *lexer)
{
	if (lexer->c == '$')
		return (advs_token(lexer, lexer_collect_env(lexer)));
	else if (lexer->c == '\'')
		return (lexer_collect_single_quote(lexer));
	else
		return (advs_token(lexer, lexer_simple_caraters(lexer)));
	return (init_token(TOKEN_EOF, "\n"));
}
