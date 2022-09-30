/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visito_wildcards.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 23:13:07 by ziloughm          #+#    #+#             */
/*   Updated: 2022/09/30 10:53:21 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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
		return (0);
	return (1);
}

void	expand_wildcards(t_node **node)
{
	DIR				*dp;
	struct dirent	*dirp;
	int				i;
	char			*s;

	i = 0;
	while ((*node)->param[i] != 0)
	{
		if (!check_inlist_expand((*node), i))
		{
			i++;
			continue ;
		}
		s = ft_strjoin("./", ft_strrrchr((*node)->param[i], '/'));
		dp = opendir(s);
		dirp = readdir(dp);
		while (dirp != 0)
		{
			if (dirp->d_name[0] != '.')
				printf("%d : %s\n", i, dirp->d_name);
			dirp = readdir(dp);
		}
		free(s);
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
