/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 13:55:39 by ibentour          #+#    #+#             */
/*   Updated: 2022/10/15 15:44:42 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	check_exit(char *arg)
{
	int		x;

	x = 0;
	while (arg && arg[x])
	{
		if (!ft_isdigit(arg[x]))
			return (0);
		x++;
	}
	return (1);
}

void	ft_exit(char **args)
{
	int		x;

	x = 0;
	g_vars.exit_code = 0;
	if (!args || args[0] == '\0')
	{
		ft_putstr_fd("exit\n", 1);
		exit(0);
	}
	if (check_exit(args[0]))
	{
		ft_putstr_fd("exit\n", 1);
		x = ft_atoi(args[0]) % 256;
	}
	else
	{
		printf("exit\nbash: exit: %s: numeric argument required\n", args[0]);
		g_vars.exit_code = 255;
	}
	exit (x);
}
