/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token_ast_free_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 00:44:28 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/03 00:45:38 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	free_cmd(t_cmd *cmd)
{
	t_cmd	*tmp;

	while (cmd)
	{
		tmp = cmd;
		cmd = cmd->next;
		free(tmp->value);
		free(tmp->input);
		free(tmp->output);
		free(tmp->append);
		free_dstr(tmp->param);
		free(tmp);
	}
}

void	free_ast(t_ast *ast)
{
	t_ast	*tmp;

	while (ast)
	{
		tmp = ast;
		ast = ast->next;
		free_cmd(ast->line_cmd);
		free(tmp);
	}
}
