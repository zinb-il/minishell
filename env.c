/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:38:28 by ibentour          #+#    #+#             */
/*   Updated: 2022/10/23 14:48:49 by ziloughm         ###   ########.fr       */
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

int	ft_env(int out, char **ast_args)
{
	t_env	*tmp;

	if (ast_args && ft_strsize(ast_args))
	{
		g_vars.exit_code = 127;
		ft_putstr_fd("minishell : env: ", 2);
		ft_putstr_fd(ast_args[0], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return (0);
	}
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
