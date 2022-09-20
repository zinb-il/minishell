/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_part.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 22:45:52 by ziloughm          #+#    #+#             */
/*   Updated: 2022/09/20 23:08:21 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	first_part(char *s)
{
	t_token	*token;

	token = lexer(s);
	if (!token || !scann_grammar(token))
	{
		free (token);
		return ;
	}
}
