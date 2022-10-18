/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_util_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibentour <ibentour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:06:39 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/18 22:07:19 by ibentour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_check_path_exist(void)
{
	t_env	*env;

	env = g_vars.env;
	if (!env)
		return (0);
	while (env)
	{
		if (!ft_strcmp(env->env_att, "PATH"))
			return (env->env_val);
		env = env->next;
	}
	return (0);
}

char	**ft_get_path(void)
{
	char	**paths;
	char	*val;
	int		i;
	char	*str;

	val = ft_check_path_exist();
	if (!val || !ft_strlen(val))
		return (0);
	paths = ft_split(val, ':');
	i = 0;
	while (paths && paths[i])
	{
		str = paths[i];
		paths[i] = ft_strjoin(paths[i], "/");
		free(str);
		i++;
	}
	return (paths);
}

int	ft_en_len(void)
{
	t_env	*env;
	int		i;

	i = 0;
	env = g_vars.env;
	if (!env)
		return (0);
	while (env)
	{
		i++;
		env = env->next;
	}
	return (i);
}

char	**ft_get_env(void)
{
	char	**tmp;
	t_env	*env;
	int		i;
	char	*s;

	i = ft_en_len() + 1;
	tmp = (char **)malloc(sizeof(char *) * i);
	env = g_vars.env;
	i = 0;
	while (env)
	{
		s = ft_strjoin(env->env_att, "=");
		tmp[i] = ft_strjoin(s, env->env_val);
		free(s);
		i++;
		env = env->next;
	}
	tmp[i] = 0;
	return (tmp);
}

void	ft_exe_cmd(char	*cmd, char **param, char **env)
{
	int		i;
	char	*s;

	i = execve(cmd, param, env);
	s = cmd;
	cmd = ft_strjoin(cmd, ": ");
	free(s);
	if (i == -1)
		ft_error(ft_strjoin(cmd, strerror(errno)), 1);
}
