/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 21:19:18 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/19 10:26:34 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handler_sigint_parent(int sigid)
{
	if (sigid == SIGINT)
	{
		if (!rl_on_new_line())
		{
			write(1, "\n", 1);
			rl_replace_line("", 1);
			rl_redisplay();
			g_vars.exit_code = 1;
		}
	}
}

void	handler_sigquit_herdoc(int sigid)
{
	if (sigid == SIGINT)
	{
		write(1, "\n", 1);
		exit(1);
	}
}

void	signals(int pro)
{
	if (pro == 0)
	{
		signal(SIGINT, handler_sigint_parent);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (pro == 1)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
	}
	else if (pro == 2)
	{
		signal(SIGINT, handler_sigquit_herdoc);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (pro == 3)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}
}
