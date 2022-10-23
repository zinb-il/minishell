/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:08:08 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/23 22:19:40 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_node_param(t_node **node, t_token *token)
{
	char	**param;
	int		i;
	int		j;

	if (!token || token->type == TOKEN_EOF || !token->value)
		return ;
	i = (int)ft_strsize((*node)->param) + 1;
	param = (char **)malloc(sizeof(char *) * (i + 1));
	j = 0;
	while ((*node)->param && (*node)->param[j])
	{
		param[j] = ft_strdup((*node)->param[j]);
		j++;
	}
	free_dstr((*node)->param);
	param[j] = ft_strdup(token->value);
	param[j + 1] = 0;
	(*node)->param = param;
}

void	check_if_expand(t_node **node, t_token *token)
{
	char	**exd_p;
	int		i;
	int		j;

	i = (int)ft_strsize((*node)->exd_p) + 1;
	exd_p = (char **)malloc(sizeof(char *) * (i + 1));
	j = 0;
	while ((*node)->exd_p && (*node)->exd_p[j])
	{
		exd_p[j] = ft_strdup((*node)->exd_p[j]);
		j++;
	}
	free_dstr((*node)->exd_p);
	if (token->type == TOKEN_WORD_EX)
		exd_p[j] = ft_strdup("0");
	if (token->type == TOKEN_WORD)
		exd_p[j] = ft_strdup("1");
	exd_p[j + 1] = 0;
	(*node)->exd_p = exd_p;
}

t_node	*advs_node(t_token **token, t_node *node)
{
	if ((*token)->next)
		(*token) = (*token)->next;
	return (node);
}

t_node	*get_node_wored_cmd(t_token **token)
{
	t_node	*node;

	node = init_node(NODE_CMD, 0);
	get_node_value(&node, *token);
	check_if_expand_cmd(&node, *token);
	(*token) = (*token)->next;
	while ((*token)->type == TOKEN_WORD || (*token)->type == TOKEN_WORD_EX)
	{
		if ((*token)->type == TOKEN_WORD_EX)
		{
			get_node_param(&node, *token);
			check_if_expand(&node, *token);
		}
		if ((*token)->type == TOKEN_WORD)
		{
			get_node_param_ex(&node, *token);
			check_if_expand_cmd(&node, *token);
		}
		(*token) = (*token)->next;
	}
	return (node);
}

t_node	*get_node_wored_herdoc(t_token **token)
{
	t_node	*node;

	node = init_node(NODE_HEREDOC, ft_strdup("<<"));
	(*token) = (*token)->next;
	if ((*token)->type == TOKEN_WORD || (*token)->type == TOKEN_WORD_EX)
	{
		get_node_param_heredoc(&node, *token);
		check_if_expand(&node, *token);
		(*token) = (*token)->next;
	}
	return (node);
}
