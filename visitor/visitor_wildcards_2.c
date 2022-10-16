/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visitor_wildcards_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:31:10 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/16 14:35:06 by ziloughm         ###   ########.fr       */
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

char	**new_expand_param(char **param, char *str, char *str1)
{
	int		s;
	int		j;
	char	**new;
	char	*str2;

	s = (int)ft_strsize(param) + 1;
	new = (char **)malloc(sizeof(char *) * (s + 1));
	j = 0;
	while (param && param[j])
	{
		new[j] = ft_strdup(param[j]);
		j++;
	}
	if (param)
		free_dstr(param);
	str2 = ft_strjoin(str1, str);
	new[j] = ft_strdup(str2);
	new[j + 1] = 0;
	free(str2);
	free(str1);
	return (new);
}

void	check_if_added_elemnt(char ***list, int i, char *s1, t_node **node)
{
	int		size;
	char	*s;

	size = (int)ft_strsize(*list);
	s = ft_strjoin("./", s1);
	ft_opendir(node, s, i, list);
	if (size == (int)ft_strsize(*list))
		*list = new_expand_param(*list, (*node)->param[i], ft_strdup(""));
	free(s);
}
