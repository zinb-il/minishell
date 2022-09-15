/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_collect_env.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 19:44:16 by ziloughm          #+#    #+#             */
/*   Updated: 2022/09/15 20:45:22 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*lexer_collect_env_val(t_lexer *lexer)
{
	int		start;
	char	*str1;

	start = lexer->i;
	while (ft_isalnum(lexer->c) || lexer->c == '_')
		lexer_advance(&lexer);
	str1 = ft_substr(lexer->content, start, lexer->i - start);
	free(str1);
	return (get_env_val(g_vars.env, str1));
}

t_token	*lexer_collect_env_str_quote(t_lexer *lexer, char *str, char c)
{
	t_token	*token;
	char	*s;

	(void)c;
	token = lexer_collect_single_quote(lexer);
	if (token->type != TOKEN_ERR)
	{
		s = token->value;
		token->value = ft_strjoin(str, token->value);
		free(s);
	}
	free(str);
	return (token);
}

t_token	*lexer_collect_env_str(t_lexer *lexer)
{
	char	*str;

	str = lexer_collect_env_val(lexer);
	if (lexer->c == '\'')
		return (lexer_collect_env_str_quote(lexer, str, '\''));
	return (init_token(TOKEN_WORD, str));
}

t_token	*lexer_collect_env(t_lexer *lexer)
{
	lexer_advance(&lexer);
	if (lexer->c == '?')
		return (advs_token(lexer, \
		init_token(TOKEN_WORD, ft_itoa(g_vars.exit_code))));
	else if (lexer->c == '$')
		return (advs_token(lexer, \
		init_token(TOKEN_WORD, ft_itoa(g_vars.child_process_pid))));
	else if (lexer->c != '\0')
		return (lexer_collect_env_str(lexer));
	else
		return (init_token(TOKEN_WORD, "$"));
}
