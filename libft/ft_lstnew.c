/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibentour <ibentour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:09:19 by ibentour          #+#    #+#             */
/*   Updated: 2022/10/07 22:45:03 by ibentour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_env	*ft_lstnew(char *name, char *value)
{
	t_env	*newlst;

	newlst = (t_env *) malloc(sizeof(t_env));
	if (!newlst)
		return (NULL);
	newlst->env_att = name;
	newlst->env_val = value;
	newlst->next = NULL;
	return (newlst);
}
