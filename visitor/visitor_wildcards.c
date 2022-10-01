/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visitor_wildcards.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 23:13:07 by ziloughm          #+#    #+#             */
/*   Updated: 2022/09/30 17:47:34 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	wild_card_matching(char *str, char *patern)
{
	int	**mat;
	int	m;
	int	n;
	int	i;
	int	j;

	m = (int)ft_strlen(str) + 1;
	n = (int)ft_strlen(patern) + 1;
	mat = (int **)ft_calloc(sizeof(int), m * n);
	i = 0;
	while (i < m)
	{
		j = 0;
		while (j < n)
		{
			printf("%d ", mat[i][j]);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_opendir(t_node **node, char *s, int i)
{
	DIR				*dp;
	struct dirent	*dirp;

	dp = opendir(s);
	dirp = readdir(dp);
	(void)node;
	(void)i;
	while (dirp != 0)
	{
		if (dirp->d_name[0] != '.')
			wild_card_matching((*node)->param[i], dirp->d_name);
		dirp = readdir(dp);
	}
	closedir(dp);
}

int	check_inlist_expand(t_node *node)
{
	char	*str;

	str = ft_strrchr(node->value, '/');
	if (!str)
		str = ft_strdup(node->value);
	else
		str++;
	if (!ft_strcmp(str, "cd") || !ft_strcmp(str, "pwd") \
	|| !ft_strcmp(str, "unset") || !ft_strcmp(str, "env") \
	|| !ft_strcmp(str, "export") || !ft_strcmp(str, "exit"))
	{
		free(str);
		return (0);
	}
	free(str);
	return (1);
}

void	expand_wildcards(t_node **node)
{
	int				i;
	char			*s;
	char			*s1;

	i = 0;
	while ((*node)->param[i] != 0)
	{
		if ((*node)->exd_p[i][0] == '1' && ft_fndc((*node)->param[i], '*'))
		{
			s1 = ft_strrrchr((*node)->param[i], '/');
			s = ft_strjoin("./", s1);
			ft_opendir(node, s, i);
			free(s);
			free(s1);
		}
		i++;
	}
}

void	wild_card(t_node *node)
{
	t_node	*tmp;

	tmp = node;
	while (tmp->type != NODE_EOF)
	{
		if (tmp->type == NODE_CMD && check_inlist_expand(tmp))
			expand_wildcards(&tmp);
		tmp = tmp->next;
	}
}
