/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 18:34:37 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/20 18:59:16 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_val(t_env *env, char *var)
{
	if (!env)
		return (0);
	while (env)
	{
		if (!ft_strcmp(env->env_att, var))
			return (ft_strdup(env->env_val));
		env = env->next;
	}
	return (0);
}

t_env	*ft_getlast_env(t_env *lst)
{
	t_env	*last;

	last = 0;
	while (lst)
	{
		last = lst;
		lst = lst->next;
	}
	return (last);
}

void	ft_addlast_env(t_env **lst, t_env *new)
{
	t_env	*last;

	if (lst && *lst)
	{
		last = ft_getlast_env(*lst);
		last->next = new;
	}
	if (!*lst)
		*lst = new;
}

t_env	*get_env_elmnt(char *line)
{
	t_env	*elm;
	char	**str;

	elm = (t_env *)malloc(sizeof(t_env));
	if (!elm)
		return (0);
	str = ft_split(line, '=');
	if (!str)
		return (0);
	elm->env_att = 0;
	elm->env_val = 0;
	elm->next = 0;
	if (str[0])
		elm->env_att = ft_strdup(str[0]);
	if (str[1])
		elm->env_val = ft_strdup(str[1]);
	free_dstr(str);
	return (elm);
}

void	get_env(char **env)
{
	int		i;
	t_env	*elm;

	i = 0;
	g_vars.env = 0;
	if (!env || !*env)
		return ;
	while (env[i])
	{
		elm = get_env_elmnt(env[i]);
		if (g_vars.env)
			ft_addlast_env(&g_vars.env, elm);
		else
			g_vars.env = elm;
		i++;
	}
	g_vars.exit_code = 0;
	g_vars.sign = 0;
	g_vars.herdo_files = 0;
}
