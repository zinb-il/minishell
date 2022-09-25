/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:11:07 by ziloughm          #+#    #+#             */
/*   Updated: 2022/09/25 16:43:36 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_node	*init_node(int type, char *value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (0);
	node->type = type;
	node->value = value;
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

void	print_nodes(t_node *nodes)
{
	t_node	*tmp;

	tmp = nodes;
	while (tmp)
	{
		printf("type %d val {{%s}}\n", tmp->type, tmp->value);
		tmp = tmp->next;
	}
}

void	add_last_node(t_node **nodes, t_node *node)
{
	t_node	*tmp;

	if (nodes || *nodes)
	{
		tmp = get_last_node(*nodes);
		tmp->next = node;
		node->prev = tmp;
	}
	if (!*nodes)
		*nodes = node;
}

t_node	*get_nodes(t_token *token)
{
	t_token	*tmp;
	t_node	*nodes;

	tmp = token;
	nodes = init_node(tmp->)
	while (tmp)
	{
		printf("type %d val {{%s}}\n", tmp->type, tmp->value);
		tmp = tmp->next;
	}
}
