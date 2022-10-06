/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:52:08 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/06 13:15:41 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_execute_single_cmd(t_cmd *line_cmd)
{
	pid_t	pid;
	int		fd[2];

	if (!ft_strlen(line_cmd->value))
		return ;
	pid = fork();
	if (pid == -1)
		ft_error(ft_strdup(strerror(errno)), 1);
	if (!pid)
	{
		fd[0] = ft_chekc_inputfile(line_cmd->input);
		fd[1] = ft_chekc_ouputfile(line_cmd->output, line_cmd->append);
		if (fd[0])
			if (dup2(fd[0], STDIN_FILENO) < 0)
				ft_error(ft_strdup(strerror(errno)), 1);
		close(fd[0]);
		if (fd[1])
			if (dup2(fd[1], STDOUT_FILENO) < 0)
				ft_error(ft_strdup(strerror(errno)), 1);
		close(fd[1]);
		ft_execute_cmd(line_cmd);
	}
}

int	ft_execute_multiple_cmd_line(t_cmd *line_cmd, int fdi)
{
	int	pid;
	int	end[2];
	int	fdout;

	fdout = 0;
	if (pipe(end) != 0)
		ft_error(ft_strdup(strerror(errno)), 1);
	pid = fork();
	if (pid == -1)
		ft_error(ft_strdup(strerror(errno)), 1);
	if (pid == 0)
	{
		fdi = ft_chekc_inputfile(line_cmd->input);
		fdout = ft_chekc_ouputfile(line_cmd->output, line_cmd->append);
		dup2(fdi, STDIN_FILENO);
		if (fdout)
			dup2(fdout, STDOUT_FILENO);
		else
			dup2(end[1], STDOUT_FILENO);
		close(fdi);
		close(end[1]);
		ft_execute_cmd(line_cmd);
	}
	close (end[1]);
	close (fdi);
	close (fdout);
	fdi = end[0];
	return (fdi);
}

void	ft_execute_multiple_cmd(t_cmd *line_cmd)
{
	int		fdi;

	fdi = 0;
	while (line_cmd)
	{
		if (!ft_strlen(line_cmd->value))
		{
			line_cmd = line_cmd->next;
			continue ;
		}
		fdi = ft_execute_multiple_cmd_line(line_cmd, fdi);
		line_cmd = line_cmd->next;
	}
}

void	ft_execute_cmd_line(t_cmd *line_cmd)
{
	int	statut;

	if (!line_cmd->next && !line_cmd->value)
		return ;
	if (!line_cmd->next)
		ft_execute_single_cmd(line_cmd);
	else
		ft_execute_multiple_cmd(line_cmd);
	waitpid(-1, &statut, 0);
	if (WIFEXITED(statut))
		g_vars.exit_code = WEXITSTATUS(statut);
}
