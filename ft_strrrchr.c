/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrrchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 23:32:32 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/18 20:11:07 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strrrchr(const char *str, int c)
{
	int		i;
	char	*p;

	p = (char *)str;
	c = (char)c;
	i = ft_strlen(p);
	while (i >= 0)
	{
		if (p[i] == c)
			return (ft_substr(str, 0, i + 1));
		i--;
	}
	return (ft_strdup(""));
}
