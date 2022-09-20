/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:02:44 by ziloughm          #+#    #+#             */
/*   Updated: 2022/09/20 23:04:49 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_token	*lexer(char *str)
{
	t_lexer	*lex;
	t_token	*token;
	t_token	*tmp;

	lex = init_lexer(str);
	if (!lex)
		return (0);
	tmp = lexer_get_next_token(lex);
	token = tmp;
	while (tmp->type != TOKEN_EOF && tmp->type != TOKEN_ERR)
	{
		tmp = lexer_get_next_token(lex);
		add_last_token(&token, tmp);
	}
	if (tmp->type == TOKEN_ERR)
	{
		get_new_promt(tmp->value);
		free_tokens(tmp);
		free_lexer(lex);
		return (0);
	}
	free_lexer(lex);
	return (token);
}
