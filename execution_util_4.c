/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_util_4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 06:31:05 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/19 13:46:49 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_dup(int fdi, int fdout)
{
	dup2(fdi, STDIN_FILENO);
	dup2(fdout, STDOUT_FILENO);
}

void	ft_clode_fd(int end0, int end1)
{
	if (end0)
		close(end0);
	if (end1)
		close(end1);
}

void	check_directry_err(t_cmd *cmd)
{
	char	*str;
	int		i;

	i = 127;
	if (ft_fndc(cmd->value, '/') && access(cmd->value, F_OK))
	{
		str = cmd->value;
		cmd->value = ft_strjoin(cmd->value, ": ");
		free (str);
		if (errno == 20)
			i = 126;
		ft_error(ft_strjoin(cmd->value, strerror(errno)), i);
	}
	if (ft_fndc(cmd->value, '/') && access(cmd->value, X_OK))
	{
		str = cmd->value;
		cmd->value = ft_strjoin(cmd->value, ": ");
		free (str);
		ft_error(ft_strjoin(cmd->value, strerror(errno)), 126);
	}
}
