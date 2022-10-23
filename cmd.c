/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 23:50:47 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/22 23:00:45 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*init_cmd(void)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(1 * sizeof(t_cmd));
	cmd->value = (void *)0;
	cmd->input = (char **)malloc(sizeof(char *));
	cmd->output = (char **)malloc(sizeof(char *));
	cmd->input[0] = 0;
	cmd->output[0] = 0;
	cmd->append = 0;
	cmd->ambg = (void *)0;
	cmd->nfound = (void *)0;
	cmd->param = (char **)malloc(sizeof(char *));
	cmd->param[0] = 0;
	cmd->files = (char **)malloc(sizeof(char *));
	cmd->files[0] = 0;
	cmd->next = (void *)0;
	return (cmd);
}

t_cmd	*last_cmd(t_cmd *cmd)
{
	t_cmd	*last;

	last = 0;
	while (cmd)
	{
		last = cmd;
		cmd = cmd->next;
	}
	return (last);
}

void	add_cmd(t_cmd **cmd, t_cmd *new_cmd)
{
	t_cmd	*tmp;

	if (cmd && *cmd)
	{
		tmp = last_cmd(*cmd);
		tmp->next = new_cmd;
	}
	if (!*cmd)
		*cmd = new_cmd;
}

void	print_dstr(char **str, char *s)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		printf("%s %d:'%s'\n", s, i, str[i]);
		i++;
	}
}

void	print_cmd(t_cmd *cmd)
{
	t_cmd	*tmp;

	tmp = cmd;
	while (tmp)
	{
		printf("cmd val: %s append:%d amg %s notf %s\n\n", tmp->value, \
		tmp->append, tmp->ambg, tmp->nfound);
		print_dstr(tmp->output, "out");
		print_dstr(tmp->input, "in");
		print_dstr(tmp->param, "param");
		print_dstr(tmp->files, "files");
		tmp = tmp->next;
	}
}
