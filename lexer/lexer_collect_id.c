/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_collect_id.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:55:16 by ziloughm          #+#    #+#             */
/*   Updated: 2022/08/26 17:37:58 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*lexer_collect_single_quote(t_lexer *lexer)
{
	char	*str;
	char	*str1;
	int		s;
	int		e;

	lexer_advance(&lexer);
	str = ft_strdup(lexer->content);
	if (!check_close_quote(str, '\'', lexer->i))
	{
		free(lexer);
		printf ("Unclosed quote near %s \n", str);
		exit (1);
	}
	s = lexer->i;
	while (lexer->c != '\0' && lexer->c != '\'')
		lexer_advance(&lexer);
	e = lexer->i;
	str1 = ft_substr(str, s, e);
	free (str);
	lexer_advance(&lexer);
	return (str1);
}

char	*lexer_simple_caraters(t_lexer *lexer)
{
	char	*str;
	char	*str1;
	int		s;
	int		e;

	str = ft_strdup(lexer->content);
	s = lexer->i;
	while (lexer->c != '\0' && ft_isalnum(lexer->c))
		lexer_advance(&lexer);
	e = lexer->i;
	str1 = ft_substr(str, s, e);
	free (str);
	lexer_advance(&lexer);
	return (str1);
}

t_token	*lexer_collect_id(t_lexer *lexer)
{
	char	*str;

	str = ft_strdup("");
	if (lexer->c == '\'')
		str = lexer_collect_single_quote(lexer);
	else if (lexer->c == '$')
		str = lexer_collect_env(lexer);
	/*else if (lexer->c == '"')
		str = lexer_collect_double_quote(lexer);*/
	else
		str = lexer_simple_caraters(lexer);
	return (init_token(TOKEN_WORD, str));
}
