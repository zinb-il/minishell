/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 00:07:09 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/16 22:30:24 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	sort_list_export(t_env *tmp)
{
	t_env	*tmp1;
	char	*s;

	tmp1 = tmp;
	while (tmp1 && tmp1->next && tmp1->env_att && tmp1->next->env_att)
	{
		if (ft_strcmp(tmp1->env_att, tmp1->next->env_att) > 0)
		{
			s = tmp1->env_att;
			tmp1->env_att = tmp1->next->env_att;
			tmp1->next->env_att = s;
			s = tmp1->env_val;
			tmp1->env_val = tmp1->next->env_val;
			tmp1->next->env_val = s;
			tmp1 = tmp;
		}
		else
			tmp1 = tmp1->next;
	}
	tmp1 = tmp;
}

t_env	*ft_dup_env(t_env *env)
{
	t_env	*tmp;
	t_env	*tmp1;
	t_env	*new;

	if (!env)
		return (0);
	tmp = env;
	tmp1 = 0;
	while (tmp)
	{
		new = (t_env *)malloc(sizeof(t_env));
		new->env_att = ft_strdup(tmp->env_att);
		if (tmp->env_val)
			new->env_val = ft_strdup(tmp->env_val);
		else
			new->env_val = 0;
		new->next = 0;
		if (tmp1)
			ft_lstadd_back(&tmp1, new);
		else
			tmp1 = new;
		tmp = tmp->next;
	}
	return (tmp1);
}

void	print_export(int out)
{
	t_env	*tmp;
	t_env	*tmp1;

	tmp = ft_dup_env(g_vars.env);
	sort_list_export(tmp);
	tmp1 = tmp;
	while (tmp && tmp->env_att)
	{
		ft_print_export_line(tmp, out);
		tmp = tmp->next;
	}
	free_env(tmp1);
	g_vars.exit_code = 0;
}

char	**find_first_ecl(char *arg)
{
	int		x;
	char	**str;

	x = 0;
	str = (char **) malloc (sizeof(char *) * 3);
	if (!str)
		return (0);
	while (arg[x] && (arg[x] != '+' && arg[x] != '='))
		x++;
	if (arg[x] && (arg[x] == '+' || arg[x] == '='))
	{
		str[0] = ft_substr(arg, 0, x);
		if (arg[x] == '+')
			str[1] = ft_strdup(arg + x + 2);
		else
			str[1] = ft_strdup(arg + x + 1);
		str[2] = 0;
	}
	else
	{
		str[0] = ft_strdup(arg);
		str[1] = 0;
		str[2] = 0;
	}
	return (str);
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
			ft_lstadd_back(&g_vars.env, ft_lstnew(ft_strdup(s[0]), 0));
		free_dstr(s);
	}
}
