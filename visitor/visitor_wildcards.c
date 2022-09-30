/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visitor_wildcards.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 23:13:07 by ziloughm          #+#    #+#             */
/*   Updated: 2022/09/30 14:01:00 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**wild_card_matching(char *patern, char *str);

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
			printf("%d : %s\n", 5, dirp->d_name);
		dirp = readdir(dp);
	}
	closedir(dp);
}

int	check_inlist_expand(t_node *node, int i)
{
	char	*str;

	str = ft_strrchr(node->value, '/');
	if (!str)
		str = ft_strdup(node->value);
	else
		str++;
	if (node->exd_p[i][0] == '0' \
	|| !ft_strcmp(str, "cd") || !ft_strcmp(str, "pwd") \
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
		if (check_inlist_expand((*node), i) && ft_fndc((*node)->param[i], '*'))
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
		if (tmp->type == NODE_CMD)
			expand_wildcards(&tmp);
		tmp = tmp->next;
	}
}
