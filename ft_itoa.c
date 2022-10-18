/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:19:52 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/18 20:11:07 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_len(long int n)
{
	int	len;

	len = 1;
	if (n < 0)
		n = -1 * n;
	while (n / 10)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static long int	ft_positive(int n)
{
	long int	n1;

	n1 = n;
	if (n1 < 0)
		n1 = -1 * n1;
	return (n1);
}

char	*ft_itoa(int n)
{
	char		*p;
	int			l;
	int			m;
	long int	n1;

	l = 0;
	m = 0;
	n1 = ft_positive(n);
	if (n < 0)
		m = 1;
	l = ft_len(n1) + m;
	p = ft_calloc(l + 1, sizeof(char));
	if (!p)
		return (0);
	p[l] = '\0';
	while (l - 1 >= m)
	{
		p[l - 1] = n1 % 10 + 48;
		n1 = n1 / 10;
		l--;
	}
	if (m)
		p[0] = '-';
	return (p);
}
