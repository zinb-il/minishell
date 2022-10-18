/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:58:23 by ibentour          #+#    #+#             */
/*   Updated: 2022/10/18 20:11:07 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*ft_lstlast(t_env *lst)
{
	t_env	*last;

	if (!lst)
		return (NULL);
	last = lst;
	while (last->next != NULL)
		last = last->next;
	return (last);
}
