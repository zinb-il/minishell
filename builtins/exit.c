/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibentour <ibentour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 13:55:39 by ibentour          #+#    #+#             */
/*   Updated: 2022/10/09 22:33:14 by ibentour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	check_exit(char **args)
{
	printf("exit\n");
	printf("minishell: exit: ");
	printf("%s", args[1]);
	printf(": numeric argument required\n");
	exit(255);
}

void	ft_exit(char **args)
{
	if (args[0] && !args[1])
	{
		g_vars.exit_code[0] = 0;
		exit(g_vars.exit_code);
	}
	if (args[1])
	{
		if (!ft_isdigit(args[1][0]))
			check_exit(args);
	}
	if (args[2])
	{
		printf("exit\n");
		printf("%s exit: too many arguments\n", PS1);
		g_vars.exit_code[0] = 1;
		return ;
	}
	else
		exit(ft_atoi(args[1]) % 256);
}
