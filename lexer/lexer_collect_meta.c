/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_collect_meta.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:06:54 by ziloughm          #+#    #+#             */
/*   Updated: 2022/09/13 15:03:18 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_token	*lexer_collect_pipe(t_lexer *lexer)
{
	lexer_advance(&lexer);
	if (lexer->c == '|')
		return (advs_token(lexer, init_token(TOKEN_DPIPE, "||")));
	return (init_token(TOKEN_PIPE, "|"));
}

t_token	*lexer_collect_and(t_lexer *lexer)
{
	lexer_advance(&lexer);
	if (lexer->c == '&')
		return (advs_token(lexer, init_token(TOKEN_DAND, "&&")));
	if (lexer->c == '>')
		return (advs_token(lexer, init_token(TOKEN_DAND, "&>")));
	return (init_token(TOKEN_AND, "&"));
}

t_token	*lexer_collect_great(t_lexer *lexer)
{
	lexer_advance(&lexer);
	if (lexer->c == '>')
		return (advs_token(lexer, init_token(TOKEN_DGREAT, ">>")));
	if (lexer->c == '&')
		return (advs_token(lexer, init_token(TOKEN_DGREAT, ">&")));
	if (lexer->c == '|')
		return (advs_token(lexer, init_token(TOKEN_DGREAT, ">|")));
	return (init_token(TOKEN_GREAT, ">"));
}

t_token	*lexer_collect_less(t_lexer *lexer)
{
	lexer_advance(&lexer);
	if (lexer->c == '<')
	{
		lexer_advance(&lexer);
		if (lexer->c == '-')
			return (advs_token(lexer, init_token(TOKEN_DLESS, "<<-")));
		return (advs_token(lexer, init_token(TOKEN_DLESS, "<<")));
	}
	if (lexer->c == '&')
		return (advs_token(lexer, init_token(TOKEN_DLESS, "<&")));
	if (lexer->c == '>')
		return (advs_token(lexer, init_token(TOKEN_DLESS, "<>")));
	return (init_token(TOKEN_LESS, "<"));
}
