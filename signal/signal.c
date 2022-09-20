/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 21:19:18 by ziloughm          #+#    #+#             */
/*   Updated: 2022/09/20 15:34:21 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	handler_sigint_parent(int sigid)
{
	if (sigid == SIGINT)
	{
		if (!rl_on_new_line())
		{
			write(1, "\n", 1);
			rl_replace_line("", 1);
			rl_redisplay();
		}
	}
}

void	handler_sigint_child(int sigid)
{
	if (sigid == SIGINT)
	{
		g_vars.exit_code = 130;
		kill(getpid(), sigid);
	}
}

void	handler_sigquit_child(int sigid)
{
	if (sigid == SIGQUIT)
	{
		g_vars.exit_code = 131;
		kill(g_vars.process_pid, sigid);
	}
}

void	signals(int pro)
{
	if (!pro)
	{
		signal(SIGINT, handler_sigint_parent);
		signal(SIGQUIT, SIG_IGN);
	}
	else
	{
		signal(SIGINT, handler_sigint_child);
		signal(SIGQUIT, handler_sigquit_child);
	}
}
