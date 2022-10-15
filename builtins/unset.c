/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:49:36 by ibentour          #+#    #+#             */
/*   Updated: 2022/10/15 15:46:20 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	check_to_unset(char **args, int x)
{
	t_env	*env;
	t_env	*tmp_free;

	env = g_vars.env;
	while (env)
	{
		if (env->env_att && !ft_strcmp(env->env_att, args[x]))
		{
			tmp_free = env;
			env = env->next;
			g_vars.env = env;
			free (tmp_free);
			return (1);
		}
		else if (env->next && env->next->env_att && \
		!ft_strcmp(env->next->env_att, args[x]))
		{
			tmp_free = env->next;
			env->next = env->next->next;
			free (tmp_free);
			return (1);
		}
		env = env->next;
	}
	return (0);
}

void	ft_unset(char **args)
{
	size_t	x;

	x = 0;
	g_vars.exit_code = 0;
	while (args && args[x])
	{
		if (check_to_unset(args, x))
			return ;
		x++;
	}
	return ;
}
