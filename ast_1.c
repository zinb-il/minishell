/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 00:24:18 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/19 09:10:04 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ast	*init_ast(int type, t_cmd *cmd)
{
	t_ast	*ast;

	ast = (t_ast *)malloc(1 * sizeof(t_ast));
	ast->type = type;
	ast->line_cmd = cmd;
	ast->next = 0;
	return (ast);
}

t_ast	*last_ast(t_ast *ast)
{
	t_ast	*last;

	last = 0;
	while (ast)
	{
		last = ast;
		ast = ast->next;
	}
	return (last);
}

void	add_ast(t_ast **ast, t_ast *new_ast)
{
	t_ast	*tmp;

	if (ast && *ast)
	{
		tmp = last_ast(*ast);
		tmp->next = new_ast;
	}
	if (!*ast)
		*ast = new_ast;
}

void	print_ast(t_ast *ast)
{
	t_ast	*tmp;

	tmp = ast;
	while (tmp)
	{
		printf("type %d\n", tmp->type);
		print_cmd(tmp->line_cmd);
		printf("-----------------------------\n");
		tmp = tmp->next;
	}
}
