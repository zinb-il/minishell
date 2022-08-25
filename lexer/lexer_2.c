/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:02:44 by ziloughm          #+#    #+#             */
/*   Updated: 2022/08/25 18:35:38 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	lexer(char *str)
{
	t_lexer	*lex;
	t_token	*token;

	lex = init_lexer(str);
	if (!lex)
		return ;
	token = lexer_get_next_token(lex);
	while (token->type != TOKEN_EOF)
	{
		printf("type %d val %s\n", token->type, token->value);
		token = lexer_get_next_token(lex);
	}
}
