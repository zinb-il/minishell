/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 10:06:10 by ibentour          #+#    #+#             */
/*   Updated: 2022/10/18 02:05:20 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char	*update_pwd(t_builtins *tl)
{
	t_env	*current_env;
	char	*tmp;

	tmp = 0;
	current_env = g_vars.env;
	while (current_env != 0)
	{
		if (ft_strcmp(current_env->env_att, "PWD") == 0)
		{
			tl->old_pwd = ft_strdup(current_env->env_val);
			free(current_env->env_val);
			current_env->env_val = getcwd(tmp, sizeof(tmp));
			return (tl->old_pwd);
		}
		current_env = current_env->next;
	}
	return (0);
}

static int	cd_to_home(void)
{
	char	*home;

	home = get_env_val(g_vars.env, "HOME");
	if (!home || !*home)
	{
		ft_putstr_fd(ERR_EXEC, 2);
		ft_putstr_fd("cd: HOME not set \n", 2);
		g_vars.exit_code = 1;
		if (!*home)
			free(home);
		return (0);
	}
	else
		chdir(home);
	free(home);
	return (1);
}

static	int	check_chdir(char **arg)
{
	if (!arg)
	{
		ft_putstr_fd("Error: Enter cd with only ", 2);
		ft_putstr_fd("a relative or absolute path !\n", 2);
		g_vars.exit_code = 1;
		return (0);
	}
	else if (arg[0] == '\0')
		return (cd_to_home());
	else if (chdir(arg[0]) != 0)
	{
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(arg[0], 2);
		ft_putstr_fd(": No such file or directory", 2);
		ft_putstr_fd("\n", 2);
		g_vars.exit_code = 1;
		return (0);
	}
	return (1);
}

void	ft_cd(char	**arg, int out)
{
	t_builtins	tl;

	(void) out;
	g_vars.exit_code = 0;
	if (check_chdir(arg))
	{
		tl.new_opwd = update_pwd(&tl);
		if (tl.new_opwd)
		{
			tl.tmp_o = ft_strdup("OLDPWD=");
			tl.to_export[0] = ft_strjoin(tl.tmp_o, tl.new_opwd);
			tl.to_export[1] = 0;
			ft_export(tl.to_export, out);
			free (tl.tmp_o);
			free (tl.new_opwd);
			free(tl.to_export[0]);
		}
	}
}
