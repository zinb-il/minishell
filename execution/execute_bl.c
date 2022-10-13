/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibentour <ibentour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 07:27:44 by ibentour          #+#    #+#             */
/*   Updated: 2022/10/09 22:28:33 by ibentour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	execute_builtin(int x, char **ast_args)
{
	if (x == 1)
		ft_export(ast_args);
	//else if (x == 2)
	//	ft_unset();
	else if (x == 3)
		ft_env();
	//else if (x == 4)
	//	cd
	else if (x == 5)
		ft_pwd();
	else if (x == 6)
		ft_echo(ast_args);
	//else if (x == 7)
	//	exit
}

int	check_builtin(char *builtin)
{
	if (!ft_strcmp(builtin, "export"))
		return (1);
	else if (!ft_strcmp(builtin, "unset"))
		return (2);
	else if (!ft_strcmp(builtin, "env"))
		return (3);
	else if (!ft_strcmp(builtin, "cd"))
		return (4);
	else if (!ft_strcmp(builtin, "pwd"))
		return (5);
	else if (!ft_strcmp(builtin, "echo"))
		return (6);
	else if (!ft_strcmp(builtin, "exit"))
		return (7);
	return (-1);
}
