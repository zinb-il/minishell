/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unlink_herdocfiles.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:16:44 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/07 15:16:45 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	add_herdo_name(char	*str)
{
	int		i;
	int		s;
	char	**herdo;

	i = 0;
	s = 2;
	if (g_vars.herdo_files)
		s = ft_strsize(g_vars.herdo_files) + 2;
	herdo = (char **)malloc(sizeof(char *) * s);
	while (g_vars.herdo_files && g_vars.herdo_files[i])
	{
		herdo[i] = ft_strdup(g_vars.herdo_files[i]);
		i++;
	}
	herdo[i] = ft_strdup(str);
	herdo[i + 1] = 0;
	if (g_vars.herdo_files)
		free_dstr(g_vars.herdo_files);
	g_vars.herdo_files = herdo;
}

void	unlik_herdo_name(void)
{
	int		i;

	i = 0;
	if (!g_vars.herdo_files)
		return ;
	while (g_vars.herdo_files[i])
	{
		unlink(g_vars.herdo_files[i]);
		i++;
	}
}
