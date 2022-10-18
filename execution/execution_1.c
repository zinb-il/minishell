/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:12:31 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/18 04:14:21 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	check_execute_builtin(t_cmd *line_cmd)
{
	int		fd;

	if (!check_inlist_builtin(line_cmd->value) && !line_cmd->next)
	{
		fd = ft_chekc_ouputfile_herdoc(line_cmd->output, line_cmd->append);
		if (!fd)
			fd = 1;
		if (fd == 2)
			return (0);
		execute_builtin(check_builtin(line_cmd->value), \
						line_cmd->param, fd);
		if (fd > 2)
			close(fd);
		return (0);
	}
	return (1);
}

void	scape_cmd_toexecute(t_ast **ast)
{
	int		p;

	p = 1;
	(*ast) = (*ast)->next->next;
	while (*ast && p)
	{
		if (*ast && (*ast)->type == AST_RPARENTH)
			p--;
		if (*ast && (*ast)->type == AST_LPARENTH)
			p++;
		(*ast) = (*ast)->next;
	}
}

void	start_execute_cmd_line(t_ast **ast)
{
	if (!ast || !*ast)
		return ;
	while (*ast && (*ast)->type != AST_EOF)
	{
		while (*ast && (((*ast)->type == AST_DOR && g_vars.exit_code == 0) \
		|| (g_vars.exit_code && (*ast)->type == AST_DAND)))
		{
			if ((*ast)->next->type == AST_CMDLINE)
				(*ast) = (*ast)->next->next;
			else if (*ast && (*ast)->next->type == AST_LPARENTH)
				scape_cmd_toexecute(ast);
			else
				(*ast) = (*ast)->next;
		}
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
	start_execute_cmd_line(&ast);
}
