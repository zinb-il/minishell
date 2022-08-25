/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 20:38:31 by ziloughm          #+#    #+#             */
/*   Updated: 2022/08/25 18:37:43 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

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
