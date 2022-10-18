/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibentour <ibentour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:57:50 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/18 22:07:19 by ibentour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_dstr(char	**str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_env(t_env *env)
{
	t_env	*tmp;

	if (env)
	{
		while (env)
		{
			tmp = env;
			free(tmp->env_att);
			free(tmp->env_val);
			env = env->next;
			free(tmp);
		}
	}
}

void	free_single_env(t_env **env)
{
	t_env	*tmp;

	if (*env)
	{
		tmp = *env;
		free(tmp->env_att);
		free(tmp->env_val);
		*env = (*env)->next;
		free(tmp);
	}
}
