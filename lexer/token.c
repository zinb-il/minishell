/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:17:33 by ziloughm          #+#    #+#             */
/*   Updated: 2022/09/13 23:01:33 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_token	*init_token(int type, char *value)
{
	t_token	*token;

	token = (t_token *)malloc(1 * sizeof(t_token));
	if (!token)
		return (0);
	token->type = type;
	token->value = value;
	return (token);
}
