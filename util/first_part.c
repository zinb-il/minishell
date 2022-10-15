/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_part.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 22:45:52 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/15 23:38:15 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	first_part(char *s)
{
	t_token	*token;
	t_node	*node;
	t_ast	*ast;

	token = lexer(s);
	if (!token || !scann_grammar(token))
	{
		g_vars.exit_code = 258;
		return ;
	}
	node = get_nodes(token);
	open_heredoc_files(node);
	wild_card(node);
	creat_output_files(node);
	ast = get_ast(node);
	free_nodes(node);
	free_tokens(token);
	second_part(ast);
	free_ast(ast);
}
