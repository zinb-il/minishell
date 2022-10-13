/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:49:47 by ibentour          #+#    #+#             */
/*   Updated: 2022/10/14 00:26:54 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	check_chars(char *arg)
{
	int	ch;

	ch = 0;
	if (!ft_isalpha(arg[0]) && arg[0] != '_')
	{
		printf("export: %s': not a valid identifier\n", arg);
		return (1);
	}
	while (arg[ch] != '\0' && arg[ch] != '=')
	{
		if (!(ft_isalnum(arg[ch]) && arg[ch] != '_') && \
		(arg[ch] == '+' && arg[ch + 1] != '='))
		{
			printf("export: %s': not a valid identifier *\n", arg);
			return (1);
		}
		ch++;
	}
	return (0);
}

char	**find_first_ecl(char *arg, char ecl)
{
	int		x;
	char	**str;

	x = 0;
	str = (char **) malloc (sizeof(char *) * 3);
	while (arg[x] && arg[x] != ecl)
		x++;
	if (arg[x] && arg[x] == ecl)
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
	char		*val_p;

	i = 0;
	val_p = NULL;
	tmp = g_vars.env;
	while (arg[i] && arg[i] != '=')
		i++;
	if (arg[i - 1] && arg[i - 1] == '+')
		att = ft_substr(arg, 0, i - 1);
	else
		att = ft_substr(arg, 0, i);
	while (tmp)
	{
		if (ft_strcmp(att, tmp->env_att) == 0)
		{
			if (arg[i] && arg[i] == '=' && arg[i - 1] != '+')
				tmp->env_val = ft_strdup(arg + i + 1);
			else if (arg[i] && arg[i] == '=' && arg[i - 1] == '+')
			{
				val_p = tmp->env_val;
				tmp->env_val = ft_strjoin(tmp->env_val, (arg + i + 1));
				free (val_p);
			}
			free (att);
			return (1);
		}
		else
			tmp = tmp->next;
	}
	free(att);
	return (0);
}

void	ft_export(char	**arg)
{
	int		i;

	i = -1;
	if (!arg || arg[0] == '\0')
		print_export();
	else
	{
		while (arg[++i])
			export_values(arg[i]);
	}
}
