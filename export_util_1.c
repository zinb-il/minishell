/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_util_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibentour <ibentour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 21:53:23 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/18 22:07:19 by ibentour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_export_line(t_env	*tmp, int out)
{
	if (!tmp->env_val)
	{
		ft_putstr_fd("declare -x ", out);
		ft_putstr_fd(tmp->env_att, out);
		ft_putstr_fd(" \n", out);
	}
	else
	{
		ft_putstr_fd("declare -x ", out);
		ft_putstr_fd(tmp->env_att, out);
		ft_putstr_fd("=\"", out);
		ft_putstr_fd(tmp->env_val, out);
		ft_putstr_fd("\"\n", out);
	}
}

void	print_export_error(char	*s)
{
	ft_putstr_fd("minishell: export: `", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd("': not a valid identifier !\n", 2);
}
