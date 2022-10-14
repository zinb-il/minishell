/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibentour <ibentour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 00:07:09 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/14 14:13:08 by ibentour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	print_export(void)
{
	t_env	*tmp;

	tmp = g_vars.env;
	while (tmp && tmp->env_att)
	{
		if (tmp->env_val == NULL)
			printf("declare -x %s\n", tmp->env_att);
		else if (tmp->env_att && tmp->env_val)
			printf("declare -x %s=\"%s\"\n", tmp->env_att, tmp->env_val);
		tmp = tmp->next;
	}
	g_vars.exit_code = 0;
}

void	export_values(char *arg)
{
	char	**s;

	if (check_chars(arg))
		return ;
	if (env_exists(arg))
		return ;
	else
	{
		s = find_first_ecl(arg);
		if (!s)
			return ;
		if (s[1])
			ft_lstadd_back(&g_vars.env, ft_lstnew(ft_strdup(s[0]), \
				ft_strdup(s[1])));
		else
			ft_lstadd_back(&g_vars.env, ft_lstnew(ft_strdup(s[0]), NULL));
		free_dstr(s);
	}
}