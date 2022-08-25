/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utile_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:05:47 by ziloughm          #+#    #+#             */
/*   Updated: 2022/08/25 19:28:20 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	check_close_quote(char *str, char c, int i)
{
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	check_spcl_char(char *str, char *c, int i)
{
	while (str[i] != '\0')
	{
		if (check_close_quote(c, str[i], 0))
			return (1);
		i++;
	}
	return (0);
}
