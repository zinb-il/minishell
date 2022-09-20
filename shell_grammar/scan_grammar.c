/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_grammar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 23:01:31 by ziloughm          #+#    #+#             */
/*   Updated: 2022/09/20 23:11:06 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	print_tokens(t_token *tokens)
{
	t_token	*tmp;

	tmp = tokens;
	while (tmp)
	{
		printf("type %d val {{%s}}\n", tmp->type, tmp->value);
		tmp = tmp->next;
	}
}

int	scann_grammar(t_token *tokens)
{
	t_token	*tmp;

	tmp = tokens;
	print_tokens(tokens);
	return (1);
}
