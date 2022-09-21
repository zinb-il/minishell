/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_grammar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 23:01:31 by ziloughm          #+#    #+#             */
/*   Updated: 2022/09/21 17:23:49 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	print_tokens(t_token *tokens)
{
	t_token	*tmp;

	tmp = tokens;
	while (tmp)
	{
		if (!tmp->prev)
			printf("rien\n");
		printf("type %d val {{%s}}\n", tmp->type, tmp->value);
		tmp = tmp->next;
	}
}

int	scann_op(t_token *token, t_token *tokens)
{
	if (!token->prev ||( \
	token->prev->type != TOKEN_WORD && token->prev->type != TOKEN_WORD_EX \
	&& token->prev->type != TOKEN_RPARENTH && \
	token->next->type != TOKEN_WORD_EX && token->next->type != TOKEN_WORD \
	&& token->next->type != TOKEN_LPARENTH && token->next->type != TOKEN_GREAT \
	&& token->next->type != TOKEN_LESS && token->next->type != TOKEN_DGREAT \
	&& token->next->type != TOKEN_DLESS && token->next->type == TOKEN_EOF))
	{
		get_new_promt(ft_strjoin(ERR_SYN, token->value));
		free_tokens(tokens);
		return (0);
	}
	return (1);
}

int	scann_redirec(t_token *token, t_token *tokens)
{
	if (token->prev && token->prev->type != TOKEN_WORD && \
	token->prev->type != TOKEN_WORD_EX && token->prev->type != TOKEN_LPARENTH \
	&& token->prev->type != TOKEN_PIPE && token->prev->type != TOKEN_DPIPE \
	&& token->prev->type != TOKEN_DAND && token->next->type != TOKEN_WORD && \
	token->next->type != TOKEN_WORD_EX)
	{
		get_new_promt(ft_strjoin(ERR_SYN, token->value));
		free_tokens(tokens);
		return (0);
	}
	return (1);
}

int	scann_grammar(t_token *tokens)
{
	t_token	*tmp;

	tmp = tokens;
	while (tmp && tmp->type != TOKEN_EOF)
	{
		if ((tmp->type == TOKEN_PIPE || tmp->type == TOKEN_DPIPE || \
		tmp->type == TOKEN_DAND) && !scann_op(tmp, tokens))
			return (0);
		if ((tmp->type == TOKEN_GREAT || tmp->type == TOKEN_DGREAT || \
		tmp->type == TOKEN_DAND) && !scann_redirec(tmp, tokens))
			return (0);
		tmp = tmp->next;
	}
	print_tokens(tokens);
	free_tokens(tokens);
	return (1);
}
