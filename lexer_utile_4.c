/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utile_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:16:59 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/23 17:57:09 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_quotes_before_pipe(int end, char *str)
{
	int	i;
	int	q;

	i = 0;
	q = 0;
	while (str && i > end)
	{
		if (str[i] == '"' || str[i] == '\'')
			q++;
		i++;
	}
	return (q % 2);
}

int	env_expand_exit_code(int start, char *str)
{
	if (!str)
		return (g_vars.exit_code);
	while (str && start >= 0)
	{
		if (str[start] == '|' && !(check_quotes_before_pipe(start, str)))
			return (0);
		if (str[start] == '|' && (check_quotes_before_pipe(start, str)))
			return (g_vars.exit_code);
		start--;
	}
	return (g_vars.exit_code);
}
