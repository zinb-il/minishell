/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_util_4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 06:31:05 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/18 20:11:09 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_dup(int fdi, int fdout)
{
	dup2(fdi, STDIN_FILENO);
	dup2(fdout, STDOUT_FILENO);
}

void	ft_clode_fd(int end0, int end1)
{
	close(end0);
	(void)(end1);
}
