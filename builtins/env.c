/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibentour <ibentour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:38:28 by ibentour          #+#    #+#             */
/*   Updated: 2022/10/06 21:57:14 by ibentour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_env(void)
{
	t_env	*tmp;

	tmp = g_vars.env;
	while (tmp)
	{
		if (tmp->env_val != NULL)
			printf("%s=%s\n", tmp->env_att, tmp->env_val);
		tmp = tmp->next;
	}
	return (0);
}
