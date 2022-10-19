/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibentour <ibentour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 16:06:37 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/18 22:07:19 by ibentour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	ft_total_word(char const *s1, char c1)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		if ((s1[i] != c1 && i == 0) \
			|| ((!s1[i - 1] || s1[i - 1] == c1) && s1[i] != c1))
			j++;
		i++;
	}
	return (j);
}

static size_t	ft_word_len(char const *s1, char c1, int pos)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (s1[pos] != '\0' && s1[pos] == c1)
		pos++;
	while (s1[pos] != '\0' && s1[pos] != c1)
	{
		count++;
		pos++;
	}
	return (count);
}

static size_t	ft_word(char *t, char const *s1, char c1, int pos)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (s1[pos] != '\0' && s1[pos] == c1)
		pos++;
	while (s1[pos] != '\0' && s1[pos] != c1)
	{
		t[i] = s1[pos];
		pos++;
		i++;
	}
	t[i] = '\0';
	return (pos);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	position;
	size_t	wordlen;
	size_t	size;
	char	**p;

	if (!s)
		return (0);
	i = 0;
	position = 0;
	wordlen = 0;
	size = ft_total_word(s, c);
	p = (char **)ft_calloc((size + 1), sizeof(char *));
	if (!p)
		return (0);
	while (i < size)
	{
		wordlen = ft_word_len(s, c, position);
		p[i] = ft_calloc(wordlen + 1, sizeof(char));
		position = ft_word(p[i], s, c, position);
		i++;
	}
	p[i] = 0;
	return (p);
}
