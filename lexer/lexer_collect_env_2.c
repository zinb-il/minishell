/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_collect_env_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 17:31:51 by ziloughm          #+#    #+#             */
/*   Updated: 2022/09/24 19:03:36 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_token	*lexer_collect_env_and(t_lexer *lexer)
{
	char	*str;

	lexer_advance(&lexer);
	if (lexer->c == '\0')
		return (init_token(TOKEN_WORD, ft_strdup("$&")));
	str = lexer_after_single_and(lexer, ft_strdup("$"));
	return (init_token(TOKEN_WORD, str));
}

t_token	*lexer_collect_env_parenth(t_lexer *lexer)
{
	char	*str;
	char	*str1;
	char	*str2;

	str = (char *)malloc(2 * sizeof(char));
	str[1] = 0;
	str1 = ft_strdup("$");
	while ((lexer->c != '\0' && !check_spcl_char(SPCL2, lexer->c)) || \
	(lexer->c == '&' && lexer->content[lexer->i + 1] != '&'))
	{
		str[0] = lexer->c;
		str2 = str1;
		str1 = ft_strjoin(str1, str);
		free(str2);
		lexer_advance(&lexer);
	}
	free(str);
	return (init_token(TOKEN_WORD, str1));
}
