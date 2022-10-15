/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibentour <ibentour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 12:28:39 by ibentour          #+#    #+#             */
/*   Updated: 2022/10/15 12:33:25 by ibentour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

static int	if_max(int sin, size_t nb)
{
	if (nb >= 9223372036854775808U)
	{
		ft_putstr_fd("exit : numeric argument required !", 2);
		g_vars.exit_code = 255;
		exit(g_vars.exit_code);
	}
	return (nb * sin);
}

int	ft_atoi(const char *str)
{
	int		sin;
	size_t	number;

	sin = 1;
	number = 0;
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
	return (if_max(sin, number));
}
