/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:24:56 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/06 12:05:28 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_node	*get_next_node_wored(t_token **token)
{
	t_node	*node;

	if ((*token)->type == TOKEN_GREAT)
		node = init_node(NODE_RED_OUT, ft_strdup(">"));
	if ((*token)->type == TOKEN_DGREAT)
		node = init_node(NODE_RED_AOUT, ft_strdup(">>"));
	if ((*token)->type == TOKEN_LESS)
		node = init_node(NODE_RED_IN, ft_strdup("<"));
	if ((*token)->type == TOKEN_DLESS)
		return (get_node_wored_herdoc(token));
	if ((*token)->type == TOKEN_WORD || (*token)->type == TOKEN_WORD_EX)
		return (get_node_wored_cmd(token));
	(*token) = (*token)->next;
	get_node_param(&node, (*token));
	return (advs_node(token, node));
}

t_node	*get_next_node(t_token **token)
{
	while ((*token)->type != TOKEN_EOF)
	{
		if ((*token)->type == TOKEN_DAND)
			return (advs_node(token, init_node(NODE_DAND, ft_strdup("&&"))));
		else if ((*token)->type == TOKEN_DPIPE)
			return (advs_node(token, init_node(NODE_DPIPE, ft_strdup("||"))));
		else if ((*token)->type == TOKEN_PIPE)
			return (advs_node(token, init_node(NODE_PIPE, ft_strdup("|"))));
		else if ((*token)->type == TOKEN_LPARENTH)
			return (advs_node(token, init_node(NODE_LPARENTH, ft_strdup("("))));
		else if ((*token)->type == TOKEN_RPARENTH)
			return (advs_node(token, init_node(NODE_RPARENTH, ft_strdup(")"))));
		else
			return (get_next_node_wored(token));
	}
	return (init_node(NODE_EOF, ft_strdup((*token)->value)));
}

t_node	*get_nodes(t_token *token)
{
	t_node	*nodes;
	t_node	*tmpn;

	nodes = get_next_node(&token);
	tmpn = nodes;
	while (tmpn && tmpn->type != NODE_EOF)
	{
		tmpn = get_next_node(&token);
		add_last_node(&nodes, tmpn);
	}
	return (nodes);
}
