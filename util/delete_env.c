/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:57:50 by ziloughm          #+#    #+#             */
/*   Updated: 2022/09/29 21:34:31 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	free_dstr(char	**str)
{
	int	i;

	i = 0;
	while (str[i])
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
