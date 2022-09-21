/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:23:27 by ziloughm          #+#    #+#             */
/*   Updated: 2022/09/21 13:41:25 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	get_new_promt(char *str)
{
	if (!rl_on_new_line())
	{
		rl_replace_line("", 1);
		rl_redisplay();
		printf("%s\n", str);
		free(str);
	}
}
