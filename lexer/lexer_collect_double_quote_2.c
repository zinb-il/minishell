/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_collect_double_quote_2.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:38:23 by ziloughm          #+#    #+#             */
/*   Updated: 2022/09/23 18:44:03 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_token	*lexer_collect_double_quote_fafter(t_lexer *lexer, char *str2)
{
	if (lexer->c == '&' && lexer->content[lexer->i + 1] != '&')
		str2 = lexer_after_single_and(lexer, str2);
	if (lexer->c != '\0' && (lexer->c == '$' || lexer->c == '\'' || \
	!check_spcl_char(SPCL, lexer->c) || lexer->c == '"'))
		return (lexer_collect_double_quote_after(lexer, str2, lexer->c));
	return (init_token(TOKEN_WORD_EX, str2));
}
