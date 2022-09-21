/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 16:15:22 by ziloughm          #+#    #+#             */
/*   Updated: 2022/09/21 12:10:58 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef TOKEN_H
# define TOKEN_H

typedef enum e_token_type
{
	TOKEN_WORD,
	TOKEN_WORD_EX,
	TOKEN_PIPE,
	TOKEN_DPIPE,
	TOKEN_DAND,
	TOKEN_GREAT,
	TOKEN_DGREAT,
	TOKEN_LESS,
	TOKEN_DLESS,
	TOKEN_EQUAL,
	TOKEN_LPARENTH,
	TOKEN_RPARENTH,
	TOKEN_EOF,
	TOKEN_ERR
}t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*value;
	struct s_token	*next;
	struct s_token	*prev;
}t_token;

t_token	*init_token(int type, char *value);
t_token	*get_last_token(t_token *token);
void	add_last_token(t_token **tokens, t_token *token);
void	free_tokens(t_token *tokens);

#	endif