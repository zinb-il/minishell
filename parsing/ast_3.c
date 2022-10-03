/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 00:54:01 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/03 19:24:26 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_ast	*advs_ast(t_node **node, t_ast *ast)
{
	(*node) = (*node)->next;
	return (ast);
}

t_ast	*get_next_ast(t_node **node)
{
	while ((*node)->type != NODE_EOF)
	{
		if ((*node)->type == NODE_LPARENTH)
			return (advs_ast(node, init_ast(AST_LPARENTH, init_cmd())));
		else if ((*node)->type == NODE_RPARENTH)
			return (advs_ast(node, init_ast(AST_RPARENTH, init_cmd())));
		else if ((*node)->type == NODE_DAND)
			return (advs_ast(node, init_ast(AST_DAND, init_cmd())));
		else if ((*node)->type == NODE_DPIPE)
			return (advs_ast(node, init_ast(AST_DOR, init_cmd())));
		else
			return (init_ast(AST_CMDLINE, get_cmd_line(node)));
	}
	return (init_ast(AST_EOF, init_cmd()));
}

t_ast	*get_ast(t_node *node)
{
	t_ast	*ast;
	t_ast	*tmp;

	tmp = get_next_ast(&node);
	ast = tmp;
	while (tmp->type != AST_EOF)
	{
		tmp = get_next_ast(&node);
		add_ast(&ast, tmp);
	}
	return (ast);
}
