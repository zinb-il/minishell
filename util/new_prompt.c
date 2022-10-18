/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:23:27 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/18 00:33:55 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	get_new_promt(char *str)
{
	ft_putstr_fd(ERR_EXEC, 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	free(str);
}

void	get_new_promt_nl(char *str)
{
	ft_putstr_fd(ERR_EXEC, 2);
	ft_putstr_fd(str, 2);
	free(str);
}
