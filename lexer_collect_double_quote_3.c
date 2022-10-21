/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_collect_double_quote_3.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:12:30 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/20 19:17:30 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*check_before_heroutin(t_lexer *lexer)
{
	if (check_herdoc(lexer))
		return (lexer_collect_quotes_herdoc(lexer, '"'));
	return (lexer_collect_quotes_ouinput(lexer, '"'));
}
