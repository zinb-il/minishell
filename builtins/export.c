/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibentour <ibentour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:49:47 by ibentour          #+#    #+#             */
/*   Updated: 2022/10/14 14:45:48 by ibentour         ###   ########.fr       */
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
	while (arg[ch] != '\0' && arg[ch] != '=')
	{
		if ((!(ft_isalnum(arg[ch])) && arg[ch] != '_' && arg[ch] != '+') \
			|| (arg[ch] == '+' && arg[ch + 1] != '='))
		{
			printf("export: `%s': not a valid identifier\n", arg);
			return (1);
		}
		ch++;
	}
	return (0);
}

char	**find_first_ecl(char *arg)
{
	int		x;
	char	**str;

	x = 0;
	str = (char **) malloc (sizeof(char *) * 3);
	if (!str)
		return (NULL);
	while (arg[x] && (arg[x] != '+' && arg[x] != '='))
		x++;
	if (arg[x] && (arg[x] == '+' || arg[x] == '='))
	{
		str[0] = ft_substr(arg, 0, x);
		if (arg[x] == '+')
			str[1] = ft_strdup(arg + x + 2);
		else
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

static int	what_to_do(t_builtins *tl, char *att, char *arg)
{
	if (ft_strcmp(att, tl->tmp->env_att) == 0)
	{
		if (arg[tl->i] && arg[tl->i] == '=' && arg[tl->i - 1] != '+')
			tl->tmp->env_val = ft_strdup(arg + tl->i + 1);
		else if (arg[tl->i] && arg[tl->i] == '=' && arg[tl->i - 1] == '+')
		{
			tl->val_p = tl->tmp->env_val;
			if (!tl->tmp->env_val)
				tl->tmp->env_val = ft_strdup(arg + tl->i + 1);
			else
				tl->tmp->env_val = ft_strjoin(tl->tmp->env_val, (arg + \
														tl->i + 1));
			free (tl->val_p);
		}
		return (1);
	}
	return (0);
}

static	int	w_env_exist(char *att, char *arg, size_t i)
{
	t_builtins	tl;

	tl.val_p = NULL;
	tl.i = i;
	tl.tmp = g_vars.env;
	while (tl.tmp)
	{
		if (what_to_do(&tl, att, arg))
			return (1);
		else
			tl.tmp = tl.tmp->next;
	}
	return (0);
}

int	env_exists(char *arg)
{
	size_t		i;
	char		*att;

	i = 0;
	while (arg[i] && arg[i] != '=')
		i++;
	if (arg[i - 1] && arg[i - 1] == '+')
		att = ft_substr(arg, 0, i - 1);
	else
		att = ft_substr(arg, 0, i);
	if (w_env_exist(att, arg, i))
	{
		free (att);
		return (1);
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
