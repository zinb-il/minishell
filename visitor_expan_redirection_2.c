/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visitor_ambiguous_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:11:00 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/21 12:55:05 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	test_ambiguous(char	*str)
{
	int		i;
	char	c;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] != '"' && str[i] != '\'')
		{
			if (str[i] == ' ' && str[i] == '\t')
				return (0);
			i++;
		}
		if (str[i] == '"' || str[i] == '\'')
		{
			c = str[i];
			i++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (1);
}
