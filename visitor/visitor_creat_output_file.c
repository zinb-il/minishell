/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visitor_creat_output_file.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 21:22:33 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/04 21:29:01 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	creat_output_files(t_node *node)
{
	t_node	*tmp;

	tmp = node;
	while (tmp && tmp->type != NODE_EOF)
	{
		if (tmp->type == NODE_RED_OUT)
			open(tmp->param[0], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (tmp->type == NODE_RED_AOUT)
			open(tmp->param[0], O_CREAT | O_RDWR | O_APPEND, 0644);
		tmp = tmp->next;
	}
}
