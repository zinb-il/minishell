/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visitor_herdoc_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:46:56 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/18 14:38:55 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	fork_for_herdoc(int fd, t_node *node)
{
	char	*str;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		ft_error(ft_strdup(strerror(errno)), 1);
	if (pid == 0)
	{
		signals(2);
		str = readline(PS2);
		while (str && ft_strcmp(str, node->param[0]))
		{
			if (!ft_strcmp(node->exd_p[0], "1"))
				expand_heredoc_variable(str, fd);
			else
				write(fd, str, ft_strlen(str));
			write(fd, "\n", 1);
			free(str);
			str = readline(PS2);
		}
		free(str);
		exit(0);
	}
	return (pid);
}

int	count_herdoc(t_node *node)
{
	t_node	*tmp;
	int		max;

	tmp = node;
	max = 0;
	while (tmp->type != NODE_EOF)
	{
		if (tmp->type == NODE_HEREDOC)
			max++;
		tmp = tmp->next;
	}
	return (max);
}
