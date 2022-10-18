/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsizecmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:59:22 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/06 22:26:15 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_lstsizecmd(t_cmd *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		++i;
		lst = lst->next;
	}
	return (i);
}
