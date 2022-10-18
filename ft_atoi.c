/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibentour <ibentour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 12:28:39 by ibentour          #+#    #+#             */
/*   Updated: 2022/10/18 22:08:00 by ibentour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	if_max(int sin, size_t nb, char *str)
{
	if (nb > 9223372036854775807)
	{
		ft_putstr_fd("minishell: exit : ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(" : numeric argument required !\n", 2);
		g_vars.exit_code = 255;
		free(str);
		exit(g_vars.exit_code);
	}
	free(str);
	return (nb * sin);
}

int	ft_atoi(const char *str)
{
	int					sin;
	unsigned long long	number;
	char				*s;

	sin = 1;
	number = 0;
	s = ft_strdup(str);
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sin *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		number = (number * 10) + (*str - 48);
		str++;
	}
	return (if_max(sin, number, (char *)s));
}
