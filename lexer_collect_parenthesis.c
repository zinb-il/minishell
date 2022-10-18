/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_collect_parenthesis.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 21:26:26 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/18 20:11:02 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*lexer_collect_parenthesis(t_lexer *lexer)
{
	if (check_close_parenthesis(lexer->content))
		return (init_token(TOKEN_ERR, ft_strjoin("Unclosed parenthe near ", \
		lexer->content)));
	if (lexer->c == '(')
		return (advs_token(lexer, init_token(TOKEN_LPARENTH, ft_strdup("("))));
	if (lexer->c == ')')
		return (advs_token(lexer, init_token(TOKEN_RPARENTH, ft_strdup(")"))));
	return (lexer_get_next_token(lexer));
}
