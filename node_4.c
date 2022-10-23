/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:37:23 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/23 22:17:54 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_node_param_heredoc(t_node **node, t_token *token)
{
	char	**param;
	int		i;
	int		j;

	if (!token || token->type == TOKEN_EOF || !token->value)
		return ;
	i = (int)ft_strsize((*node)->param) + 1;
	param = (char **)malloc(sizeof(char *) * (i + 2));
	j = 0;
	while ((*node)->param && (*node)->param[j])
	{
		param[j] = ft_strdup((*node)->param[j]);
		j++;
	}
	free_dstr((*node)->param);
	param[j] = ft_strdup(token->value);
	param[j + 1] = ft_strdup(token->value);
	param[j + 2] = 0;
	(*node)->param = param;
}

void	get_node_param_ex(t_node **node, t_token *token)
{
	char	**param;
	char	**ex;
	int		j;
	int		i;

	ex = ft_split(token->value, ' ');
	param = (char **)malloc(sizeof(char *) * ((int)ft_strsize((*node)->param) + \
	(int)ft_strsize(ex) + 2));
	j = 0;
	while ((*node)->param && (*node)->param[j])
	{
		param[j] = ft_strdup((*node)->param[j]);
		j++;
	}
	i = 0;
	while (ex && ex[i])
	{
		param[j] = ft_strdup(ex[i]);
		j++;
		i++;
	}
	free_dstr((*node)->param);
	free_dstr(ex);
	param[j] = 0;
	(*node)->param = param;
}

void	get_node_param_ex1(t_node **node, t_token *token)
{
	char	**ex;
	int		size;
	int		j;

	ex = ft_split(token->value, ' ');
	if (ft_strsize(ex) == 1)
	{
		(*node)->value = ft_strdup(ex[0]);
		free_dstr(ex);
		return ;
	}
	free_dstr((*node)->param);
	size = (int)ft_strsize(ex) - 1;
	(*node)->param = (char **)malloc(sizeof(char *) * (size + 1));
	j = 1;
	if (ex && ex[0])
		(*node)->value = ft_strdup(ex[0]);
	while (ex && ex[j])
	{
		(*node)->param[j - 1] = ft_strdup(ex[j]);
		j++;
	}
	(*node)->param[size] = 0;
	free_dstr(ex);
}

void	check_if_expand_cmd(t_node **node, t_token *token)
{
	char	**exd_p;
	int		i;
	int		j;
	int		s;

	i = (int)ft_strsize((*node)->exd_p);
	s = (int)ft_strsize((*node)->param);
	exd_p = (char **)malloc(sizeof(char *) * (s + 1));
	j = 0;
	while ((*node)->exd_p && (*node)->exd_p[j])
	{
		exd_p[j] = ft_strdup((*node)->exd_p[j]);
		j++;
	}
	free_dstr((*node)->exd_p);
	while (j < s)
	{
		if (token->type == TOKEN_WORD_EX)
			exd_p[j] = ft_strdup("0");
		if (token->type == TOKEN_WORD)
			exd_p[j] = ft_strdup("1");
		j++;
	}
	exd_p[s] = 0;
	(*node)->exd_p = exd_p;
}

void	get_node_value(t_node **node, t_token *token)
{
	if (!token->value)
		(*node)->value = 0;
	else
	{
		if (token->type == TOKEN_WORD_EX)
			(*node)->value = ft_strdup(token->value);
		if (token->type == TOKEN_WORD)
			get_node_param_ex1(node, token);
	}
	return ;
}
