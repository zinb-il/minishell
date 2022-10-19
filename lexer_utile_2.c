/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utile_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibentour <ibentour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:05:47 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/18 22:07:19 by ibentour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_close_quote(char *str, char c, int i)
{
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	get_new_str(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\'' || str[i] == '"')
		{
			if (!j)
				j++;
			else
				j--;
			i++;
			continue ;
		}
		if (j && (str[i] == ')' || str[i] == '('))
			str[i] = 'A';
		i++;
	}
}

int	check_close_parenthesis(char *str)
{
	int		j;
	int		i;
	char	*str1;

	j = 0;
	i = 0;
	str1 = ft_strdup(str);
	get_new_str(str1);
	while (str1[i] != '\0')
	{
		if (str1[i] == '(')
			j++;
		if (str1[i] == ')')
			j--;
		i++;
	}
	free(str1);
	return (j);
}

int	check_spcl_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*add_dollar_or_not(char *str, int i)
{
	char	*s;

	if (!i)
	{
		s = str;
		str = ft_strjoin("$", str);
		free(s);
	}
	return (str);
}
