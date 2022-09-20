/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:24:11 by ziloughm          #+#    #+#             */
/*   Updated: 2022/09/20 17:38:36 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	init_minishell(char **env)
{
	get_env(env);
	signals(0);
}

int	str_redline(char *str)
{
	if (!str)
	{
		printf("\rexit\n");
		return (0);
	}
	if (!*str)
		return (1);
	return (2);
}
