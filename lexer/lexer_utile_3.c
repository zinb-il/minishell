/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utile_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 23:37:23 by ziloughm          #+#    #+#             */
/*   Updated: 2022/09/23 18:36:34 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*lexer_after_single_and(t_lexer *lexer, char *str1)
{
	char	*str;
	char	*str2;

	str2 = str1;
	str1 = ft_strjoin(str1, "&");
	free(str2);
	str = (char *)malloc(2 * sizeof(char));
	if (!str)
		return (str1);
	str[1] = 0;
	lexer_advance(&lexer);
	while ((lexer->c != '\0' && !check_spcl_char(SPCL, lexer->c)) || \
	(lexer->c == '&' && lexer->content[lexer->i + 1] != '&'))
	{
		str[0] = lexer->c;
		str2 = str1;
		str1 = ft_strjoin(str1, str);
		free(str2);
		lexer_advance(&lexer);
	}
	free(str);
	return (str1);
}
