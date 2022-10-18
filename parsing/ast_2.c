/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:30:21 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/18 18:27:01 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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

void	free_oldin_out(char	**str1, char *str2)
{
	if (str1 && *str1 && ft_strlen(*str1) > 0)
		free(*str1);
	*str1 = ft_strdup(str2);
}

void	add_cmd_val_toparam(t_cmd **tmp, t_node	**node)
{
	if (!(*tmp)->value)
	{
		(*tmp)->value = ft_strdup((*node)->value);
		if ((*tmp)->param)
			free_dstr((*tmp)->param);
		(*tmp)->param = ft_strdup_d((*node)->param);
	}
	else
		add_cmd_to_cmd(tmp, node);
}

t_cmd	*get_next_cmd(t_node **node)
{
	t_cmd	*tmp;

	tmp = init_cmd();
	while (node && not_other_ast(node) && (*node)->type != NODE_PIPE)
	{
		if ((*node)->type == NODE_CMD)
			add_cmd_val_toparam(&tmp, node);
		if ((*node)->type == NODE_RED_IN || (*node)->type == NODE_HEREDOC)
			free_oldin_out(&(tmp->input), (*node)->param[0]);
		if ((*node)->type == NODE_RED_OUT || (*node)->type == NODE_RED_AOUT)
			free_oldin_out(&(tmp->output), (*node)->param[0]);
		if ((*node)->type == NODE_RED_OUT)
			tmp->append = 0;
		if ((*node)->type == NODE_RED_AOUT)
			tmp->append = 1;
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
	}
	return (cmd_line);
}
