/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 13:55:39 by ibentour          #+#    #+#             */
/*   Updated: 2022/10/16 15:46:11 by ziloughm         ###   ########.fr       */
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
	if (!args || !*args)
	{
		ft_putstr_fd("exit\n", 1);
		exit(g_vars.exit_code);
	}
	else if (check_exit(args[0]) && ft_strsize(args) == 1)
	{
		ft_putstr_fd("exit\n", 1);
		g_vars.exit_code = ft_atoi(args[0]) % 256;
		exit (g_vars.exit_code);
	}
	else if (check_exit(args[0]) && ft_strsize(args) > 1)
	{
		printf("exit\nbash: exit: %s: too many arguments\n", args[0]);
		g_vars.exit_code = 1;
	}
	else
	{
		printf("exit\nbash: exit: %s: numeric argument required\n", args[0]);
		g_vars.exit_code = 255;
		exit (g_vars.exit_code);
	}
}
