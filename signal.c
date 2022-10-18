/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 21:19:18 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/18 20:11:02 by ziloughm         ###   ########.fr       */
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

void	handler_sigint_child(int sigid)
{
	if (sigid == SIGINT)
		g_vars.exit_code = 130;
}

void	handler_sigquit_child(int sigid)
{
	if (sigid == SIGQUIT)
	{
		write(2, "Quit: 3\n", 8);
		g_vars.exit_code = 131;
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
		signal(SIGINT, handler_sigint_child);
		signal(SIGQUIT, handler_sigquit_child);
	}
	else
	{
		signal(SIGINT, handler_sigquit_herdoc);
		signal(SIGQUIT, SIG_IGN);
	}
}
