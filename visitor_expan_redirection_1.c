/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visitor_expan_redirection_1.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 22:05:16 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/21 16:03:14 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	joind_str(char **s1, char *s2)
{
	char	*s;

	if (!s1)
	{
		*s1 = ft_strdup(s2);
		return ;
	}
	s = *s1;
	*s1 = ft_strjoin(*s1, s2);
	free(s);
}

int	env_redirection(char	*str, char **s1, int i)
{
	int		start;
	char	*str1;
	char	*str2;

	i++;
	if (!str[i])
	{
		joind_str(s1, "$");
		return (i);
	}
	start = i;
	while (ft_isalnum(str[i]) || str[i] == '_')
		i++;
	str1 = ft_substr(str, start, i - start);
	str2 = get_env_val(g_vars.env, str1);
	free(str1);
	str1 = *s1;
	*s1 = ft_strjoin(*s1, str2);
	if (str1)
		free(str1);
	if (str2)
		free(str2);
	return (i);
}

int	d_quotes_redirection(char	*str, char **s1, int i)
{
	char	str1[2];

	i++;
	str1[1] = 0;
	str1[0] = '"';
	joind_str(s1, str1);
	while (str[i] && str[i] != '"')
	{
		if (str[i] == '$')
			i = env_redirection(str, s1, i);
		else
		{
			str1[0] = str[i];
			joind_str(s1, str1);
			i++;
		}
	}
	str1[0] = '"';
	joind_str(s1, str1);
	i++;
	return (i);
}

int	s_quotes_redirection(char	*str, char **s1, int i)
{
	char	str1[2];

	i++;
	str1[1] = 0;
	str1[0] = '\'';
	joind_str(s1, str1);
	while (str[i] && str[i] != '\'')
	{
		str1[0] = str[i];
		joind_str(s1, str1);
		i++;
	}
	str1[0] = '\'';
	joind_str(s1, str1);
	i++;
	return (i);
}

char	*trim_str(char *str)
{
	char	*s;
	int		i;
	int		start;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	start = i;
	i = ft_strlen(str) - 1;
	while (str[i] && i >= 0 && (str[i] == ' ' || str[i] == '\t'))
		i--;
	s = ft_substr(str, start, i - start + 1);
	free(str);
	str = s;
	return (str);
}
