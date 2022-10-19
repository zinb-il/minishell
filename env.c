/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibentour <ibentour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:38:28 by ibentour          #+#    #+#             */
/*   Updated: 2022/10/18 22:07:19 by ibentour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_env_line(char *s1, char *s2, int out)
{
	ft_putstr_fd(s1, out);
	ft_putstr_fd("=", out);
	ft_putstr_fd(s2, out);
	ft_putstr_fd("\n", out);
}

int	ft_env(int out)
{
	t_env	*tmp;

	tmp = g_vars.env;
	while (tmp)
	{
		if (tmp && tmp->env_val != 0)
			print_env_line(tmp->env_att, tmp->env_val, out);
		tmp = tmp->next;
	}
	g_vars.exit_code = 0;
	return (0);
}
