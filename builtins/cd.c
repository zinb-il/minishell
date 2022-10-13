/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibentour <ibentour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 10:06:10 by ibentour          #+#    #+#             */
/*   Updated: 2022/10/07 21:32:57 by ibentour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	searchch(char *word, char *changed, t_env *env_list)
{
	t_env	*current;

	current = env_list;
	while (current != NULL)
	{
		if (ft_strcmp(current->env_val, word) == 0)
		{
			free(current->env_val);
			current->env_val = changed;
			break ;
		}
		current = current->next;
	}
}

char	*get_home_incd(t_env *env_list)
{
	t_env	*current;
	char	*home;

	home = NULL;
	current = env_list;
	while (current != NULL)
	{
		if (ft_strcmp(current->env_val, "HOME") == 0)
		{
			home = current->env_val;
			break ;
		}
		current = current->next;
	}
	return (home);
}

void	ft_cd(char **args, t_env *env_list)
{
	char	*pwd;
	char	*path;
	char	*home;

	path = NULL;
	path = getcwd(path, 0);
	home = get_home_incd(env_list);
	pwd = NULL;
	if (ft_strcmp(".", args[1]) == 0 || args[1] == NULL)
		args[1] = home;
	if (chdir(args[1]) != 0)
	{
		ft_putstr(2, "Minishell: cd: ");
		ft_putstr(2, args[1]);
		ft_putstr(2, ": No such file or directory\n");
		g_vars.exit_code[1] = 1;
	}
	pwd = getcwd(pwd, 0);
	searchch("PWD", pwd, env_list);
	searchch("OLDPWD", path, env_list);
}
