/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visitor_creat_output_file_1.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 21:22:33 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/22 22:29:53 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*join_three_str(char *s1, char	*s2, char *s3)
{
	char	*str;
	char	*str1;

	str1 = ft_strjoin(s1, s2);
	str = ft_strjoin(str1, s3);
	free(str1);
	return (str);
}

int	test_in_first(t_node **t, int *d)
{
	int	fd;

	*d = 0;
	if (ft_strsize((*t)->param) == 1)
	{
		(*t)->ambg = ft_strjoin((*t)->param[0], ": ambiguous redirect");
		*d = 1;
		return (1);
	}
	fd = open((*t)->param[1], O_RDONLY);
	if (fd < 0)
	{
		(*t)->nfound = join_three_str((*t)->param[1], ": ", strerror(errno));
		*d = 1;
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

void	unset_param(char **str)
{
	if (str)
	{
		free(*str);
		*str = 0;
	}
}

int	test_ou_first(t_node **t, int *d)
{
	int	fd;

	if (*d == 1)
		return (1);
	if (ft_strsize((*t)->param) == 1)
	{
		(*t)->ambg = ft_strjoin((*t)->param[0], ": ambiguous redirect");
		return (1);
	}
	if ((*t)->type == NODE_RED_OUT)
		fd = open((*t)->param[1], O_RDWR | O_TRUNC, 0644);
	if ((*t)->type == NODE_RED_AOUT)
		fd = open((*t)->param[1], O_RDWR | O_APPEND, 0644);
	if (fd < 0)
	{
		(*t)->nfound = join_three_str((*t)->param[1], ": ", strerror(errno));
		fd = open((*t)->param[1], O_CREAT, 0644);
		if (fd < 0)
			return (1);
		unlink((*t)->param[1]);
		unset_param(&((*t)->nfound));
		(*t)->files = ft_strdup((*t)->param[1]);
	}
	close(fd);
	return (0);
}
