/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visitor_creat_output_file_2.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 21:49:45 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/22 21:53:02 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	creat_output_files(t_node **node)
{
	t_node	*tmp;
	int		dr;

	tmp = *node;
	dr = 0;
	while (tmp && tmp->type != NODE_EOF)
	{
		if ((tmp->type == NODE_RED_IN && test_in_first(&tmp, &dr)) \
		|| (tmp->type == NODE_RED_OUT && test_ou_first(&tmp, &dr)) \
		|| (tmp->type == NODE_RED_AOUT && test_ou_first(&tmp, &dr)))
		{
			tmp = tmp->next;
			while (tmp && not_other_ast(&tmp) && tmp->type != NODE_PIPE)
				tmp = tmp->next;
		}
		else
			tmp = tmp->next;
	}
}
