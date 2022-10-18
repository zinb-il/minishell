/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token_ast_free_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibentour <ibentour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 00:44:28 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/18 22:07:19 by ibentour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_cmd(t_cmd *cmd)
{
	t_cmd	*tmp;

	while (cmd)
	{
		tmp = cmd;
		cmd = cmd->next;
		if (tmp->value)
			free(tmp->value);
		if (tmp->input)
			free(tmp->input);
		if (tmp->output)
			free(tmp->output);
		if (tmp->param)
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
		if (tmp->line_cmd)
			free_cmd(tmp->line_cmd);
		free(tmp);
	}
}
