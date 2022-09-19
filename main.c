/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 20:38:31 by ziloughm          #+#    #+#             */
/*   Updated: 2022/09/19 23:02:27 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

void	print_env(t_env *env)
{
	while (env)
	{
		printf("%s=========%s \n", env->env_att, env->env_val);
		env = env->next;
	}
}

int	main(int ac, char **av, char **env)
{
	char	*str;
	int		i;

	(void)ac;
	(void)av;
	init_minishell(env);
	while (1)
	{
		str = readline(PS1);
		i = str_redline(str);
		if (!i || i == 1)
			free(str);
		if (!i)
			break ;
		if (i == 1)
			continue ;
		add_history(str);
		lexer(str);
		free(str);
	}
	return (0);
}
