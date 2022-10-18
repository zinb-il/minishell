/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_util_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibentour <ibentour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:48:07 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/18 23:02:35 by ibentour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

	if (!env || !ft_strsize(env) || !path || !ft_strsize(path))
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
	{
		if (g_vars.exit_code == 1)
			exit(1);
		exit(0);
	}
	path = ft_get_path();
	env = ft_get_env();
	if ((ft_strrchr(cmd->value, '/') && !access(cmd->value, F_OK | X_OK)) \
	|| !path )
		ft_exe_cmd(cmd->value, new_expand_param2(cmd->param, cmd->value), env);
	ft_execute_cmd_join(cmd, path, env);
	free_dstr(path);
	free_dstr(env);
	ft_error(ft_strjoin(cmd->value, ": command not found"), 127);
}

void	check_ouin_multcmd(t_cmd *line_cmd, int *fdi, int *fdo)
{
	int	f1;
	int	f2;

	f1 = ft_chekc_inputfile(line_cmd->input);
	f2 = ft_chekc_ouputfile(line_cmd->output, line_cmd->append);
	if (f1)
		*fdi = f1;
	if (f2 > 0)
		*fdo = f2;
	if (!f2 && !line_cmd->next)
		*fdo = 1;
}

int	check_builtin_letters(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		s[i] = ft_tolower(s[i]);
		i++;
	}
	if (!ft_strcmp(s, "pwd") || !ft_strcmp(s, "env") || !ft_strcmp(s, "echo"))
		return (0);
	return (1);
}
