/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:38:28 by ibentour          #+#    #+#             */
/*   Updated: 2022/10/15 15:44:17 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_env(void)
{
	t_env	*tmp;

	tmp = g_vars.env;
	while (tmp)
	{
		if (tmp && tmp->env_val != NULL)
			printf("%s=%s\n", tmp->env_att, tmp->env_val);
		tmp = tmp->next;
	}
	g_vars.exit_code = 0;
	return (0);
}
