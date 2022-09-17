/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_collect_meta.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:06:54 by ziloughm          #+#    #+#             */
/*   Updated: 2022/09/17 22:54:27 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_token	*lexer_collect_pipe(t_lexer *lexer)
{
	lexer_advance(&lexer);
	if (lexer->c == '|')
		return (advs_token(lexer, init_token(TOKEN_DPIPE, ft_strdup("||"))));
	return (init_token(TOKEN_PIPE, ft_strdup("|")));
}

t_token	*lexer_collect_and(t_lexer *lexer)
{
	t_token	*token;
	char	*s;

	lexer_advance(&lexer);
	if (lexer->c == '&')
		return (init_token(TOKEN_DAND, ft_strdup("&&")));
	token = lexer_get_next_token(lexer);
	if (token->type != TOKEN_ERR)
	{
		s = token->value;
		token->value = ft_strjoin("&", token->value);
		free(s);
	}
	return (token);
}

t_token	*lexer_collect_great(t_lexer *lexer)
{
	lexer_advance(&lexer);
	if (lexer->c == '>')
		return (advs_token(lexer, init_token(TOKEN_DGREAT, ft_strdup(">>"))));
	return (init_token(TOKEN_GREAT, ft_strdup(">")));
}

t_token	*lexer_collect_less(t_lexer *lexer)
{
	lexer_advance(&lexer);
	if (lexer->c == '<')
		return (advs_token(lexer, init_token(TOKEN_DLESS, ft_strdup("<<"))));
	return (init_token(TOKEN_LESS, ft_strdup("<")));
}
