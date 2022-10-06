/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:52:08 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/06 10:42:17 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_execute_single_cmd(t_cmd *line_cmd)
{
	pid_t	pid;
	int		fd[0];

	pid = fork();
	if (pid == -1)
		ft_error(ft_strdup(strerror(errno)), 1);
	if (!pid)
	{
		fd[0] = ft_chekc_inputfile(line_cmd->input);
		fd[1] = ft_chekc_ouputfile(line_cmd->output, line_cmd->append);
		if (fd[0])
		{
			if (dup2(fd[0], STDIN_FILENO) < 0)
				ft_error(ft_strdup(strerror(errno)), 1);
			close(fd[0]);
		}
		if (fd[1])
		{
			if (dup2(fd[1], STDOUT_FILENO) < 0)
				ft_error(ft_strdup(strerror(errno)), 1);
			close(fd[1]);
		}
		ft_execute_cmd(line_cmd);
	}
}

void	ft_execute_cmd_line(t_cmd *line_cmd)
{
	int	statut;

	if (!line_cmd->next || !line_cmd->value || !ft_strlen(line_cmd->value))
		get_new_promt(ft_strdup(""));
	if (!line_cmd->next)
		ft_execute_single_cmd(line_cmd);
	waitpid(-1, &statut, 0);
	if (WIFEXITED(statut))
		g_vars.exit_code = WEXITSTATUS(statut);
}
