/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_part.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 22:45:52 by ziloughm          #+#    #+#             */
/*   Updated: 2022/09/29 23:19:44 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	first_part(char *s)
{
	t_token	*token;
	t_node	*node;

	token = lexer(s);
	if (!token || !scann_grammar(token))
		return ;
	node = get_nodes(token);
	//print_nodess(node);
	open_heredoc_files(node);
	wild_card(node);
	free_nodes(node);
	free_tokens(token);
}
