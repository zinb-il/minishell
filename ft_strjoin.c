/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibentour <ibentour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:11:16 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/18 22:07:19 by ibentour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	char	*p;

	if (!s2 || !s1)
		return (0);
	i = ft_strlen(s1) + ft_strlen(s2) + 1;
	p = (char *)malloc(i * sizeof(char));
	if (!p)
		return (0);
	*p = 0;
	ft_strlcat(p, s1, i);
	ft_strlcat(p, s2, i);
	return (p);
}
