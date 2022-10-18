/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibentour <ibentour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:16:26 by ibentour          #+#    #+#             */
/*   Updated: 2022/10/18 22:07:19 by ibentour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(int out)
{
	char	cwd[256];

	g_vars.exit_code = 0;
	if (getcwd(cwd, sizeof(cwd)) == 0)
	{
		g_vars.exit_code = 1;
		perror("Error : ");
	}
	else
	{
		ft_putstr_fd(cwd, out);
		ft_putstr_fd("\n", out);
	}
}
