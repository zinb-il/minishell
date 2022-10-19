/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibentour <ibentour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 19:06:48 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/18 22:07:19 by ibentour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_strdup_d(char	**param)
{
	char	**dup;
	int		i;

	if (!param)
		return (0);
	dup = (char **)malloc((ft_strsize(param) + 1) * sizeof(char *));
	i = 0;
	while (param[i])
	{
		dup[i] = ft_strdup(param[i]);
		i++;
	}
	dup[i] = 0;
	return (dup);
}
