/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:12:31 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/17 00:32:33 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	check_execute_builtin(t_ast *ast)
{
	t_ast	*tmp;
	int		fd;

	tmp = ast;
	if (tmp->type == AST_CMDLINE && !check_inlist_builtin(tmp->line_cmd->value) \
	&& !tmp->line_cmd->next)
	{
		fd = ft_chekc_ouputfile(tmp->line_cmd->output, tmp->line_cmd->append);
		if (!fd)
			fd = 1;
		execute_builtin(check_builtin(tmp->line_cmd->value), \
						tmp->line_cmd->param, fd);
		if (fd > 2)
			close(fd);
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
		if (*ast && (*ast)->type == AST_EOF)
			break ;
		while (*ast && (((*ast)->type == AST_DOR && g_vars.exit_code == 0) \
		|| (g_vars.exit_code && (*ast)->type == AST_DAND)))
			(*ast) = (*ast)->next->next;
		if (*ast && (*ast)->type == AST_CMDLINE)
			ft_execute_cmd_line((*ast)->line_cmd);
		if (*ast)
			(*ast) = (*ast)->next;
	}
}

void	second_part(t_ast *ast)
{
	if (!ast)
		return ;
	if (!check_execute_builtin(ast))
		ast = ast->next;
	start_execute_cmd_line(&ast);
}
