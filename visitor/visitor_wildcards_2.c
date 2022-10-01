/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visitor_wildcards_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:31:10 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/01 23:55:21 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	**init_matrix(int m, int n)
{
	int		**mat;
	int		i;
	int		j;

	mat = (int **)malloc((m + 1) * sizeof(int *));
	i = 0;
	while (i < (m + 1))
	{
		mat[i] = (int *)malloc((n + 1) * sizeof(int));
		i++;
	}
	i = 0;
	while (i < (m + 1))
	{
		j = 0;
		while (j < (n + 1))
		{
			mat[i][j] = 0;
			j++;
		}
		i++;
	}
	mat[0][0] = 1;
	return (mat);
}

char	*find_patern(char *param)
{
	char	*str;
	char	*patern;

	str = ft_strrchr(param, '/');
	if (!str)
		patern = ft_strdup(param);
	else
		patern = ft_substr(str, 1, ft_strlen(str) - 1);
	return (patern);
}

char	**new_expand_param(char **param, char *str)
{
	int		s;
	int		i;
	char	**new;

	s = (int)ft_strsize(param) + 1;
	new = (char **)malloc(sizeof(char *) * (s + 1));
	i = 0;
	while (param && param[j])
	{
		new[j] = ft_strdup(param[j]);
		j++;
	}
	free_dstr(param);
	new[j] = ft_strdup(token->value);
	new[j + 1] = 0;
	return (new);
}
