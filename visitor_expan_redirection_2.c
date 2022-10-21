/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visitor_expan_redirection_2.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:11:00 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/21 19:06:49 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	test_ambiguous(char	*str)
{
	int		i;
	char	c;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] != '"' && str[i] != '\'')
		{
			if ((str[i] == ' ' || str[i] == '\t') && str[i + 1])
				return (0);
			i++;
		}
		if (str[i] == '"' || str[i] == '\'')
		{
			c = str[i];
			i++;
			while (str[i] && str[i] != c)
				i++;
			i++;
		}
	}
	return (1);
}

void	join_char_to_str(char **s, char c, int *i)
{
	char	s2[2];

	s2[1] = 0;
	s2[0] = c;
	joind_str(s, s2);
	(*i)++;
}

char	*clean_the_str(char	*str)
{
	int		i;
	char	*s1;
	char	c;

	if (!str || !*str)
		return (0);
	i = 0;
	s1 = 0;
	while (str[i])
	{
		while (str[i] && str[i] != '"' && str[i] != '\'')
			join_char_to_str(&s1, str[i], &i);
		if (str[i] && (str[i] == '"' || str[i] == '\''))
		{
			c = str[i];
			i++;
			while (str[i] && str[i] != c)
				join_char_to_str(&s1, str[i], &i);
			if ((str[i - 1] == '"' || str[i - 1] == '\'') && !ft_strlen(s1))
				return (ft_strdup(""));
			i++;
		}
	}
	free(str);
	return (s1);
}
