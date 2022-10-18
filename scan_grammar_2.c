/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_grammar_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 20:03:47 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/18 20:11:02 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	scann_grammar2(t_token *tokens)
{
	t_token	*tmp;

	tmp = tokens;
	while (tmp && tmp->type != TOKEN_EOF)
	{
		if (tmp->type == TOKEN_DLESS && !scann_redirec(tmp, tokens))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
