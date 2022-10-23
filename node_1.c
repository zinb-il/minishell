/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:11:07 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/23 21:07:07 by ziloughm         ###   ########.fr       */
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
	node->files = (void *)0;
	node->ambg = (void *)0;
	node->nfound = (void *)0;
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
		printf("node type %d val {{%s}} amg %s notf %s files %s\n", \
		tmp->type, tmp->value, tmp->ambg, tmp->nfound, tmp->files);
		i = 0;
		while (tmp->param && tmp->param[i])
		{
			printf("param node  '%s' \n", tmp->param[i]);
			i++;
		}
		i = 0;
		while (tmp->exd_p && tmp->exd_p[i])
		{
			printf("exp node  '%s' \n", tmp->exd_p[i]);
			i++;
		}
		printf("\n");
		tmp = tmp->next;
	}
}
