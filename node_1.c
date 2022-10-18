/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibentour <ibentour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:11:07 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/18 22:07:19 by ibentour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node	*init_node(int type, char *value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (0);
	node->type = type;
	node->value = value;
	node->param = (char **)malloc(sizeof(char *));
	node->exd_p = (char **)malloc(sizeof(char *));
	node->param[0] = 0;
	node->exd_p[0] = 0;
	node->next = (void *)0;
	node->prev = (void *)0;
	return (node);
}

t_node	*get_last_node(t_node *node)
{
	t_node	*last;

	last = 0;
	while (node)
	{
		last = node;
		node = node->next;
	}
	return (last);
}

void	add_last_node(t_node **nodes, t_node *node)
{
	t_node	*tmp;

	if (nodes && *nodes)
	{
		tmp = get_last_node(*nodes);
		tmp->next = node;
		node->prev = tmp;
	}
	if (!*nodes)
		*nodes = node;
}

void	print_nodess(t_node *nodes)
{
	t_node	*tmp;
	int		i;

	tmp = nodes;
	while (tmp)
	{
		printf("node type %d val {{%s}}\n", tmp->type, tmp->value);
		i = 0;
		while (tmp->param && tmp->param[i])
		{
			printf("param  %s \n", tmp->param[i]);
			i++;
		}
		printf("\n");
		tmp = tmp->next;
	}
}
