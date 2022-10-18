/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 23:50:47 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/18 20:10:50 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*init_cmd(void)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(1 * sizeof(t_cmd));
	cmd->value = (void *)0;
	cmd->input = (void *)0;
	cmd->output = (void *)0;
	cmd->append = 0;
	cmd->param = (char **)malloc(sizeof(char *));
	cmd->param[0] = 0;
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

void	print_cmd(t_cmd *cmd)
{
	t_cmd	*tmp;
	int		i;

	tmp = cmd;
	while (tmp)
	{
		printf("val: %s input:%s output:%s append:%d \n", tmp->value, \
		tmp->input, tmp->output, tmp->append);
		i = 0;
		while (tmp->param && tmp->param[i])
		{
			printf("param %d:%s\n", i, tmp->param[i]);
			i++;
		}
		tmp = tmp->next;
	}
}
