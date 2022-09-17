/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_collect_id.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:55:16 by ziloughm          #+#    #+#             */
/*   Updated: 2022/09/17 22:29:51 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_token	*lexer_collect_id(t_lexer *lexer)
{
	if (lexer->c == '$')
		return (lexer_collect_env(lexer));
	else if (lexer->c == '\'')
		return (lexer_collect_single_quote(lexer));
	else if (lexer->c == '"')
		return (lexer_collect_double_quote(lexer));
	else
		return (lexer_simple_caraters(lexer));
	return (init_token(TOKEN_EOF, "\n"));
}
