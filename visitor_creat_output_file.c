/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visitor_creat_output_file.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibentour <ibentour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 21:22:33 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/18 22:30:05 by ibentour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int	test_input_first(char *str)
{
	int	t;
	int	fd;

	fd = open(str, O_RDONLY);
	t = 1;
	if (fd < 0)
		t = 0;
	close(fd);
	return (t);
}

void	creat_output_files(t_node *node)
{
	t_node	*tmp;
	int		fd;
	int		t;

	tmp = node;
	fd = 0;
	t = 1;
	while (tmp && tmp->type != NODE_EOF)
	{
		if (tmp->type == NODE_RED_IN && tmp->param[0])
			t = test_input_first(tmp->param[0]);
		if (tmp->type == NODE_RED_OUT && t)
		{
			fd = open(tmp->param[0], O_CREAT | O_RDWR | O_TRUNC, 0644);
			close(fd);
		}
		if (tmp->type == NODE_RED_AOUT && t)
		{
			fd = open(tmp->param[0], O_CREAT | O_RDWR | O_APPEND, 0644);
			close(fd);
		}
		tmp = tmp->next;
	}
}
