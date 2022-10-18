/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:52:08 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/18 07:30:21 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_execute_single_cmd(t_cmd *line_cmd)
{
	pid_t	pid;
	int		fd[2];

	signals(1);
	pid = fork();
	if (pid == -1)
		ft_error(ft_strdup(strerror(errno)), 1);
	g_vars.child_process_pid = pid;
	if (!pid)
	{
		fd[0] = ft_chekc_inputfile(line_cmd->input);
		fd[1] = ft_chekc_ouputfile(line_cmd->output, line_cmd->append);
		if (fd[0])
		{
			dup2(fd[0], STDIN_FILENO);
			close(fd[0]);
		}
		if (fd[1])
		{
			dup2(fd[1], STDOUT_FILENO);
			close(fd[1]);
		}
		ft_execute_cmd(line_cmd);
	}
	g_vars.pids[0] = pid;
}

void	ft_check_tons_pipes(int pid)
{
	if (pid == -1)
		g_vars.exit_code = 1;
}

int	ft_execute_multiple_cmd_line(t_cmd *cmd, int fdi, int i)
{
	int	pid;
	int	end[2];

	signals(1);
	pipe(end);
	pid = fork();
	ft_check_tons_pipes(pid);
	g_vars.child_process_pid = pid;
	if (pid == 0)
	{
		check_ouin_multcmd(cmd, &fdi, &end[1]);
		ft_dup(fdi, end[1]);
		close (end[0]);
		if (check_inlist_builtin(cmd->value))
			ft_execute_cmd(cmd);
		execute_builtin(check_builtin(cmd->value), cmd->param, end[1]);
		exit(g_vars.exit_code);
	}
	if (fdi != 0)
		close(fdi);
	close(end[1]);
	fdi = end[0];
	g_vars.pids[i] = pid;
	return (fdi);
}

void	ft_execute_multiple_cmd(t_cmd *line_cmd)
{
	int		fdi;
	int		i;

	fdi = 0;
	i = 0;
	while (line_cmd)
	{
		fdi = ft_execute_multiple_cmd_line(line_cmd, fdi, i);
		line_cmd = line_cmd->next;
		i++;
	}
}

void	ft_execute_cmd_line(t_cmd *line_cmd)
{
	int	statut;
	int	s;
	int	i;

	if (!check_execute_builtin(line_cmd))
		return ;
	s = (int)ft_lstsizecmd(line_cmd);
	g_vars.pids = (int *)malloc(s * sizeof(int));
	if (!line_cmd->next)
		ft_execute_single_cmd(line_cmd);
	else
		ft_execute_multiple_cmd(line_cmd);
	i = -1;
	while (++i < s)
		waitpid(g_vars.pids[i], &statut, 0);
	free(g_vars.pids);
	if (WIFEXITED(statut))
		g_vars.exit_code = WEXITSTATUS(statut);
	signals(0);
}
