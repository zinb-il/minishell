/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibentour <ibentour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 13:55:39 by ibentour          #+#    #+#             */
/*   Updated: 2022/10/18 22:07:19 by ibentour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_exit(char *arg)
{
	int		x;

	x = 0;
	if (arg && (arg[x] == '-' || arg[x] == '+'))
		x++;
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
		printf("exit\nminishell: exit: %s: too many arguments\n", args[0]);
		g_vars.exit_code = 1;
	}
	else
	{
		printf("exit\nminishell: exit: %s: numeric argument required\n", args[0]);
		g_vars.exit_code = 255;
		exit (g_vars.exit_code);
	}
}
