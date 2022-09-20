/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:02:44 by ziloughm          #+#    #+#             */
/*   Updated: 2022/09/20 15:41:17 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	print_tokens(t_token *tokens)
{
	while (tokens)
	{
		printf("type %d val {{%s}}\n", tokens->type, tokens->value);
		tokens = tokens->next;
	}
}

void	lexer(char *str)
{
	t_lexer	*lex;
	t_token	*token;
	t_token	*tmp;

	lex = init_lexer(str);
	if (!lex)
		return ;
	token = lexer_get_next_token(lex);
	if (token->type == TOKEN_ERR)
		printf("%s \n", token->value);
	add_last_token(&token, token);
	if (token->type != TOKEN_EOF && token->type != TOKEN_ERR)
	{
		tmp = lexer_get_next_token(lex);
		while (tmp->type != TOKEN_EOF && tmp->type != TOKEN_ERR)
		{
			add_last_token(&token, tmp);
			tmp = lexer_get_next_token(lex);
		}
	}
	if (token->type == TOKEN_ERR || tmp->type == TOKEN_ERR)
		printf("%s \n", token->value);
	free_tokens(token);
	free_lexer(lex);
}
