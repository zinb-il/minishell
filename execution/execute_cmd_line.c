/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:52:08 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/14 20:17:03 by ziloughm         ###   ########.fr       */
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
			dup2(fd[0], STDIN_FILENO);
		if (fd[1])
			dup2(fd[1], STDOUT_FILENO);
		ft_execute_cmd(line_cmd);
	}
}

int	ft_execute_multiple_cmd_line(t_cmd *line_cmd, int fdi)
{
	int	pid;
	int	end[2];

	signals(1);
	pipe(end);
	pid = fork();
	g_vars.child_process_pid = pid;
	if (pid == 0)
	{
		check_ouin_multcmd(line_cmd, &fdi, &end[1]);
		dup2(fdi, STDIN_FILENO);
		dup2(end[1], STDOUT_FILENO);
		close(end[0]);
		if (!check_inlist_builtin(line_cmd->value))
			execute_builtin(check_builtin(line_cmd->value), line_cmd->param);
		ft_execute_cmd(line_cmd);
	}
	if (fdi != 0)
		close(fdi);
	close(end[1]);
	fdi = end[0];
	return (fdi);
}

void	ft_execute_multiple_cmd(t_cmd *line_cmd)
{
	int		fdi;

	fdi = 0;
	while (line_cmd)
	{
		fdi = ft_execute_multiple_cmd_line(line_cmd, fdi);
		line_cmd = line_cmd->next;
	}
}

void	ft_execute_cmd_line(t_cmd *line_cmd)
{
	int	statut;
	int	s;

	s = (int)ft_lstsizecmd(line_cmd);
	if (!line_cmd->next)
		ft_execute_single_cmd(line_cmd);
	else
		ft_execute_multiple_cmd(line_cmd);
	while (s > 0)
	{
		waitpid(-1, &statut, 0);
		s--;
	}
	if (WIFEXITED(statut))
		g_vars.exit_code = WEXITSTATUS(statut);
	printf("exit code %d\n", g_vars.exit_code);
	signals(0);
}
