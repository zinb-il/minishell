/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_part.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 22:45:52 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/18 07:43:16 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	sub_first_part(t_node **node, t_token **token)
{
	if (!scann_grammar(*token))
	{
		g_vars.exit_code = 258;
		free_nodes(*node);
		return (1);
	}
	wild_card(*node);
	creat_output_files(*node);
	return (0);
}

void	first_part(char *s)
{
	t_token	*token;
	t_node	*node;
	t_ast	*ast;

	token = lexer(s);
	if (!token || !scann_grammar2(token))
	{
		g_vars.exit_code = 258;
		return ;
	}
	node = get_nodes(token);
	if (open_heredoc_files(node) || sub_first_part(&node, &token))
	{
		free_nodes(node);
		free_tokens(token);
		return ;
	}
	ast = get_ast(node);
	free_nodes(node);
	free_tokens(token);
	second_part(ast);
	free_ast(ast);
}
