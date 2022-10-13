/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibentour <ibentour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:49:47 by ibentour          #+#    #+#             */
/*   Updated: 2022/10/12 02:37:48 by ibentour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	check_chars(char *arg)
{
	int		ch;

	ch = 0;
	if (!ft_isalpha(arg[0]) && arg[0] != '_')
	{
		printf("export: `%s': not a valid identifier\n", arg);
		return (1);
	}
	while (arg[ch] != '\0' && !((arg[ch] == '+'\
							&& arg[ch + 1] == '=') || arg[ch] != '='))
	{
		if (!(ft_isalnum(arg[ch]) && arg[ch] == '_') || (arg[ch] == '+'\
							&& arg[ch + 1] != '='))
		{
			printf("export: `%s': not a valid identifier *\n", arg);
			return (1);
		}
		ch++;
	}
	return (0);
}

char	**find_first_ecl(char *arg, char ecl)
{
	int		x;
	int		e;
	char	**str;

	e = 0;
	x = 0;
	str = (char **) malloc (sizeof(char *) * 3);
	while (arg[x] && (arg[x] != '+' || arg[x] != ecl))
		x++;
	if (arg[x] && (arg[x] == ecl || arg[x] == '+'))
	{
		str[0] = ft_substr(arg, 0, x);
		str[1] = ft_strdup(arg + x + 1);
		str[2] = NULL;
	}
	else
	{
		str[0] = ft_strdup(arg);
		str[1] = NULL;
		str[2] = NULL;
	}
	return (str);
}

int	env_exists(char *arg)
{
	t_env		*tmp;
	char		*att;
	size_t		i;

	i = 0;
	tmp = g_vars.env;
	while (arg[i] && arg[i] != '=')
		i++;
	att = ft_substr(arg, 0, i);
	while (tmp)
	{
		if (ft_strcmp(att, tmp->env_att) == 0)
		{
			if (arg[i] && arg[i] == '=' && arg[i - 1] != '+')
				tmp->env_val = ft_strdup(arg + i + 1);
			else if (arg[i] && arg[i] == '=' && arg[i - 1] == '+')
				tmp->env_att = ft_strjoin(tmp->env_att, (arg + i + 1));
			free (att);
			return (1);
		}
		else
			tmp = tmp->next;
	}
	free(att);
	return (0);
}

void	export_values(char *arg)
{
	char	**s;

	if (check_chars(arg))
		return ;
	if (env_exists(arg) == 1)
		return ;
	else
	{
		s = find_first_ecl(arg, '=');
		if (!s)
			return ;
		ft_lstadd_back(&g_vars.env, ft_lstnew(s[0], s[1]));
	}
}

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
}

void	ft_export(char	**arg)
{
	int		i;

	i = -1;
	if (!arg || arg[0] == NULL )
		print_export();
	else
	{
		while (arg[++i])
			export_values(arg[i]);
		//print_export();
	}
}