/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_util_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibentour <ibentour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:48:07 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/07 21:51:55 by ibentour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**new_expand_param2(char **param, char *str)
{
	int		j;
	int		i;
	char	**new;

	new = (char **)malloc(sizeof(char *) * ((int)ft_strsize(param) + 2));
	i = 0;
	new[i] = ft_strdup(str);
	j = 0;
	i++;
	while (param && param[j])
	{
		new[i] = ft_strdup(param[j]);
		j++;
		i++;
	}
	new[i] = 0;
	if (param)
		free_dstr(param);
	return (new);
}

void	ft_execute_cmd_join(t_cmd *c, char **path, char **env)
{
	char	*s;
	int		i;

	if (!path || !ft_strsize(path))
		ft_error(ft_strjoin(c->value, ": No such file or directory"), 127);
	i = 0;
	while (path[i])
	{
		s = ft_strjoin(path[i], c->value);
		if (!access(s, F_OK | X_OK))
			ft_exe_cmd(s, new_expand_param2(c->param, s), env);
		free(s);
		i++;
	}
}

void	ft_execute_cmd(t_cmd *cmd)
{
	char	**path;
	char	**env;

	if (!cmd->value || !ft_strlen(cmd->value))
		exit(0);
	path = ft_get_path();
	env = ft_get_env();
	if (!env || !ft_strsize(env))
		ft_error(ft_strjoin(cmd->value, ": No such file or directory"), 127);
	if (ft_strrchr(cmd->value, '/') && !access(cmd->value, F_OK | X_OK))
		ft_exe_cmd(cmd->value, new_expand_param2(cmd->param, cmd->value), env);
	ft_execute_cmd_join(cmd, path, env);
	free_dstr(path);
	free_dstr(env);
	ft_error(ft_strjoin(cmd->value, ": command not found"), 127);
}
