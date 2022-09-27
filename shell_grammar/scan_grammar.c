/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_grammar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 23:01:31 by ziloughm          #+#    #+#             */
/*   Updated: 2022/09/25 19:01:49 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	scann_op(t_token *token, t_token *tokens)
{
	int	i ;

	i = 0;
	if (!token->prev || token->next->type == TOKEN_EOF)
		i = 0;
	if (!!token->prev && (token->prev->type == TOKEN_WORD \
	|| token->prev->type == TOKEN_WORD_EX \
	|| token->prev->type == TOKEN_RPARENTH))
		i++;
	else
		i = 0;
	if (i && (token->next->type != TOKEN_WORD_EX \
	&& token->next->type != TOKEN_WORD \
	&& token->next->type != TOKEN_LPARENTH && token->next->type != TOKEN_GREAT \
	&& token->next->type != TOKEN_LESS && token->next->type != TOKEN_DGREAT \
	&& token->next->type != TOKEN_DLESS))
		i = 0;
	if (!i)
	{
		get_new_promt(ft_strjoin(ERR_SYN, token->value));
		free_tokens(tokens);
		return (0);
	}
	return (1);
}

int	scann_redirec(t_token *token, t_token *tokens)
{
	int	i ;

	i = 0;
	if (!token->prev || token->prev->type == TOKEN_WORD || \
	token->prev->type == TOKEN_WORD_EX || token->prev->type == TOKEN_LPARENTH \
	|| token->prev->type == TOKEN_PIPE || token->prev->type == TOKEN_DPIPE \
	|| token->prev->type == TOKEN_DAND)
		i++;
	else
		i = 0;
	if (token->next->type != TOKEN_WORD && token->next->type != TOKEN_WORD_EX)
		i = 0;
	if (!i)
	{
		get_new_promt(ft_strjoin(ERR_SYN, token->value));
		free_tokens(tokens);
		return (0);
	}
	return (1);
}

int	scann_lparenth(t_token *token, t_token *tokens)
{
	int	i ;

	i = 0;
	if (!token->prev || token->prev->type == TOKEN_DAND || \
	token->prev->type == TOKEN_LPARENTH || token->prev->type == TOKEN_PIPE \
	|| token->prev->type == TOKEN_DPIPE)
		i++;
	else
		i = 0;
	if (token->next->type == TOKEN_PIPE || token->next->type == TOKEN_DPIPE \
	|| token->next->type == TOKEN_DAND || token->next->type == TOKEN_RPARENTH \
	|| token->next->type == TOKEN_EOF)
		i = 0;
	if (!i)
	{
		get_new_promt(ft_strjoin(ERR_SYN, token->value));
		free_tokens(tokens);
		return (0);
	}
	return (1);
}

int	scann_rparenth(t_token *token, t_token *tokens)
{
	int	i ;

	i = 0;
	if (!token->prev)
		i = 0;
	if (!!token->prev && (token->prev->type == TOKEN_WORD \
	|| token->prev->type == TOKEN_WORD_EX))
		i++;
	else
		i = 0;
	if (token->next->type != TOKEN_PIPE && token->next->type != TOKEN_DPIPE \
	&& token->next->type != TOKEN_DAND && token->next->type != TOKEN_LPARENTH \
	&& token->next->type != TOKEN_EOF)
		i = 0;
	if (!i)
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
		tmp->type == TOKEN_LESS || tmp->type == TOKEN_DLESS) \
		&& !scann_redirec(tmp, tokens))
			return (0);
		if (tmp->type == TOKEN_LPARENTH && !scann_lparenth(tmp, tokens))
			return (0);
		if (tmp->type == TOKEN_RPARENTH && !scann_rparenth(tmp, tokens))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
