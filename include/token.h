/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 16:15:22 by ziloughm          #+#    #+#             */
/*   Updated: 2022/08/23 19:26:51 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef TOKEN_H
# define TOKEN_H

typedef enum e_token_type
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_DPIPE,
	TOKEN_AND,
	TOKEN_DAND,
	TOKEN_GREAT,
	TOKEN_DGREAT,
	TOKEN_LESS,
	TOKEN_DLESS,
	TOKEN_EQUAL,
	TOKEN_EOF
}t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*value;
}t_token;

t_token	*init_token(int type, char *value);

#	endif