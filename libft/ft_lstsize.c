/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibentour <ibentour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:57:57 by ibentour          #+#    #+#             */
/*   Updated: 2022/10/06 17:22:54 by ibentour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_lstsize(t_env *lst)
{
	int		x;
	t_env	*temp;

	if (!lst)
		return (0);
	temp = lst;
	x = 0;
	while (temp != NULL)
	{
		x++;
		temp = temp->next;
	}
	return (x);
}
