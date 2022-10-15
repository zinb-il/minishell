/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:16:26 by ibentour          #+#    #+#             */
/*   Updated: 2022/10/15 15:46:02 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_pwd(void)
{
	char	cwd[256];

	g_vars.exit_code = 0;
	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		g_vars.exit_code = 1;
		perror("Error : ");
	}
	else
		printf("%s\n", cwd);
}
