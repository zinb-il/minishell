/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 18:34:37 by ziloughm          #+#    #+#             */
/*   Updated: 2022/08/22 20:04:28 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_env	*ft_getlast_env(t_env *lst)
{
	t_env	*last;

	last = NULL;
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
		return (NULL);
	str = ft_split(line, '=');
	if (!str)
		return (NULL);
	elm->env_att = NULL;
	elm->env_val = NULL;
	elm->next = NULL;
	if (str[0])
		elm->env_att = str[0];
	if (str[1])
		elm->env_val = str[1];
	return (elm);
}

void	get_env(char **env)
{
	int		i;
	t_env	*elm;

	i = 0;
	g_vars.env = NULL;
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
}
