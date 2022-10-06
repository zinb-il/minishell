/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:12:31 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/06 12:15:12 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	check_execute_builtin(t_ast *ast)
{
	t_ast	*tmp;

	tmp = ast;
	if (tmp->type == AST_CMDLINE && !check_inlist_builtin(tmp->line_cmd->value) \
	&& !tmp->line_cmd->next)
	{
		printf("execute bultin in main\n");
		return (0);
	}
	return (1);
}

void	start_execute_cmd_line(t_ast **ast)
{
	if (!ast || !*ast)
		return ;
	while (*ast && (*ast)->type != AST_EOF)
	{
		if ((*ast)->type == AST_EOF || \
		(g_vars.exit_code && (*ast)->type == AST_DAND) \
		|| (!g_vars.exit_code && (*ast)->type == AST_DOR))
			break ;
		if ((*ast)->type == AST_CMDLINE)
			ft_execute_cmd_line((*ast)->line_cmd);
		(*ast) = (*ast)->next;
	}
}

void	second_part(t_ast *ast)
{
	if (!ast)
		return ;
	if (!check_execute_builtin(ast))
		return ;
	start_execute_cmd_line(&ast);
}
