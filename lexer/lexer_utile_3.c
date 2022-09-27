/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utile_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 23:37:23 by ziloughm          #+#    #+#             */
/*   Updated: 2022/09/27 16:23:58 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*lexer_after_single_and(t_lexer *lexer, char *str1)
{
	char	*str;
	char	*str2;

	str2 = str1;
	lexer_advance(&lexer);
	str1 = ft_strjoin(str1, "&");
	free(str2);
	str = (char *)malloc(2 * sizeof(char));
	if (!str)
		return (str1);
	str[1] = 0;
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

int	check_herdoc(t_lexer *lexer)
{
	char	*str;
	int		i;

	str = ft_strdup(lexer->content);
	i = lexer->i - 1;
	while (i > 0 && (str[i] == '\t' || str[i] == ' '))
		i--;
	if (i > 0 && str[i] == '<')
		i--;
	if (i >= 0 && str[i] == '<' && str[i + 1] == '<')
	{
		free(str);
		return (1);
	}
	free(str);
	return (0);
}

char	*get_herdoc_str(t_lexer *lexer, char c)
{
	char	*str;
	int		start;

	lexer_advance(&lexer);
	start = lexer->i;
	while (lexer->c != '\0' && lexer->c != c)
		lexer_advance(&lexer);
	str = ft_substr(lexer->content, start, lexer->i - start);
	lexer_advance(&lexer);
	return (str);
}
