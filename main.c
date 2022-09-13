/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 20:38:31 by ziloughm          #+#    #+#             */
/*   Updated: 2022/09/13 22:15:36 by ziloughm         ###   ########.fr       */
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

	(void)ac;
	(void)av;
	str = NULL;
	get_env(env);
	//signals(0);
	while (1)
	{
		str = readline(PS1);
		if (!str)
		{
			printf("exit\n");
			free (str);
			break ;
		}
		if (!*str)
			continue ;
		add_history(str);
		lexer(str);
		free(str);
	}
	return (0);
}
