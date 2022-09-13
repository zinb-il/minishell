/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_collect_env.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 19:44:16 by ziloughm          #+#    #+#             */
/*   Updated: 2022/09/13 22:31:32 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_token	*lexer_collect_env(t_lexer *lexer)
{
	int		start;
	char	*str;
	char	*str1;

	lexer_advance(&lexer);
	if (lexer->c == '?')
		return (init_token(TOKEN_WORD, ft_itoa(g_vars.exit_code)));
	else if (lexer->c == '$')
		return (init_token(TOKEN_WORD, ft_itoa(g_vars.child_process_pid)));
	else if (lexer->c != '\0')
	{
		str = ft_strdup(lexer->content);
		start = lexer->i;
		while (ft_isalnum(lexer->c) || lexer->c == '_')
			lexer_advance(&lexer);
		str1 = ft_substr(str, start, lexer->i - start);
		free(str);
		return (init_token(TOKEN_WORD, get_env_val(g_vars.env, str1)));
	}
	else
		return (init_token(TOKEN_WORD, "$"));
}
