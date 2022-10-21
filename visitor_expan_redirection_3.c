/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visitor_expan_redirection_3.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:55:40 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/21 13:18:15 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*char_redirection(char	*str)
{
	int		i;
	char	*s1;
	char	s2[2];

	if (!str)
		return (0);
	i = 0;
	s2[1] = 0;
	s1 = 0;
	while (str && str[i])
	{
		if (str[i] == '$')
			i = env_redirection(str, &s1, i);
		else if (str[i] == '"')
			i = d_quotes_redirection(str, &s1, i);
		else if (str[i] == '\'')
			i = s_quotes_redirection(str, &s1, i);
		else
		{
			s2[0] = str[i];
			joind_str(&s1, s2);
			i++;
		}
	}
	return (s1);
}

void	add_expanded_toparam(t_node **node, char *str)
{
	int		i;
	int		j;
	char	**param;

	if (!str)
		return ;
	i = (int)ft_strsize((*node)->param) + 1;
	param = (char **)malloc(sizeof(char *) * (i + 1));
	j = 0;
	while ((*node)->param && (*node)->param[j])
	{
		param[j] = ft_strdup((*node)->param[j]);
		j++;
	}
	free_dstr((*node)->param);
	param[j] = str;
	param[j + 1] = 0;
	(*node)->param = param;
}

char	*clean_str(char	*str)
{
	int	i;
	return (0);
}

char	*test_and_clean(char *str)
{
	if (!str || !trim_str(char_redirection(str)) || !test_ambiguous(str))
		return (0);
	clean_str(str);
}

void	expanded_rediretions(t_node *node)
{
	t_node	*tmp;

	tmp = node;
	while (tmp && tmp->type != NODE_EOF)
	{
		if (tmp->type == NODE_RED_AOUT || tmp->type == NODE_RED_OUT \
		|| tmp->type == NODE_RED_IN)
			add_expanded_toparam(&tmp, \
			trim_str(char_redirection(tmp->param[0])));
		tmp = tmp->next;
	}
}
