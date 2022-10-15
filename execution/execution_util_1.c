/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_util_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:14:21 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/15 23:43:40 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_error(char *msg, int i)
{
	if (!msg)
		return ;
	get_new_promt(msg);
	exit(i);
}

int	check_inlist_builtin(char *s)
{
	char	*str;

	if (!s)
		return (1);
	str = ft_strrchr(s, '/');
	if (!str)
		str = ft_strdup(s);
	else
		str = ft_substr(s, 1, ft_strlen(s) - 1);
	if (!ft_strcmp(str, "cd") || !ft_strcmp(str, "pwd") \
	|| !ft_strcmp(str, "unset") || !ft_strcmp(str, "env") \
	|| !ft_strcmp(str, "export") || !ft_strcmp(str, "exit") \
	|| !ft_strcmp(str, "echo"))
	{
		free(str);
		return (0);
	}
	free(str);
	return (1);
}

int	ft_chekc_inputfile(char *str)
{
	int		fd;
	char	*s1;
	char	*s2;

	if (!str)
		return (0);
	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		s1 = ft_strjoin(str, ": ");
		s2 = ft_strjoin(s1, strerror(errno));
		free(s1);
		ft_error(s2, 1);
	}
	return (fd);
}

int	ft_chekc_ouputfile(char *str, int app)
{
	int		fd;
	char	*s1;
	char	*s2;

	if (!str)
		return (0);
	if (!app)
		fd = open(str, O_CREAT | O_RDWR | O_TRUNC, 0644);
	else
		fd = open(str, O_CREAT | O_RDWR | O_APPEND, 0644);
	if (fd < 0)
	{
		s1 = ft_strjoin(str, ": ");
		s2 = ft_strjoin(s1, strerror(errno));
		free(s1);
		ft_error(s2, 1);
	}
	return (fd);
}
