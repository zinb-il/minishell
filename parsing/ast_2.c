/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:30:21 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/03 21:03:56 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**ft_strdup_d(char	**param)
{
	char	**dup;
	int		i;

	if (!param)
		return (0);
	dup = (char **)malloc((ft_strsize(param) + 1) * sizeof(char *));
	i = 0;
	while (param[i])
	{
		dup[i] = ft_strdup(param[i]);
		i++;
	}
	dup[i] = 0;
	return (dup);
}

int	not_other_ast(t_node **node)
{
	if (!node)
		return (0);
	if ((*node)->type != NODE_EOF && \
	(*node)->type != NODE_LPARENTH && (*node)->type != NODE_RPARENTH && \
	(*node)->type != NODE_DAND && (*node)->type != NODE_DPIPE)
		return (1);
	return (0);
}

t_cmd	*get_next_cmd(t_node **node)
{
	t_cmd	*tmp;

	tmp = init_cmd();
	while (node && not_other_ast(node) && (*node)->type != NODE_PIPE)
	{
		if ((*node)->type == NODE_CMD)
		{
			tmp->value = ft_strdup((*node)->value);
			if (tmp->param)
				free_dstr(tmp->param);
			tmp->param = ft_strdup_d((*node)->param);
		}
		if ((*node)->type == NODE_RED_IN || (*node)->type == NODE_HEREDOC)
			tmp->input = ft_strdup((*node)->param[0]);
		if ((*node)->type == NODE_RED_OUT)
			tmp->output = ft_strdup((*node)->param[0]);
		if ((*node)->type == NODE_RED_AOUT)
			tmp->append = ft_strdup((*node)->param[0]);
		(*node) = (*node)->next;
	}
	return (tmp);
}

t_cmd	*get_cmd_line(t_node **node)
{
	t_cmd	*cmd_line;
	t_cmd	*tmp;

	tmp = get_next_cmd(node);
	cmd_line = tmp;
	while (node && not_other_ast(node))
	{
		if ((*node)->type == NODE_PIPE)
			(*node) = (*node)->next;
		tmp = get_next_cmd(node);
		add_cmd(&cmd_line, tmp);
		if ((*node)->next)
			(*node) = (*node)->next;
	}
	return (cmd_line);
}
