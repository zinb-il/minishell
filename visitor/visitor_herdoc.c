/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visito_herdoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:53:07 by ziloughm          #+#    #+#             */
/*   Updated: 2022/09/29 22:36:50 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_join_env_str(char **str3, char *str2)
{
	char	*s;

	s = *str3;
	*str3 = ft_strjoin(*str3, str2);
	free(s);
	free(str2);
}

int	herdoc_env_val(char *str, int i, char **str3)
{
	char	*variable;
	char	*str2;
	int		start;

	i++;
	if (!ft_isalnum(str[i]) && str[i] != '_')
	{
		str2 = ft_strdup("$");
		return (i);
	}
	start = i;
	while (ft_isalnum(str[i]) || str[i] == '_')
		i++;
	variable = ft_substr(str, start, i - start);
	str2 = get_env_val(g_vars.env, variable);
	free(variable);
	variable = (*str3);
	(*str3) = ft_strjoin((*str3), str2);
	free(variable);
	free(str2);
	return (i);
}

void	expand_heredoc_variable(char *str, int fd)
{
	char	*str3;
	int		i;
	int		start;

	i = 0;
	str3 = ft_strdup("");
	while (str[i] != '\0')
	{
		start = i;
		while (str[i] != '$' && str[i] != '\0')
			++i;
		if (i > start)
			ft_join_env_str(&str3, ft_substr(str, start, i - start));
		if (str[i] == '$')
			i = herdoc_env_val(str, i, &str3);
	}
	write(fd, str3, ft_strlen(str3));
	free(str3);
}

void	write_inside_heredoc(t_node *node)
{
	char	*str;
	char	*name;
	int		fd;

	name = ft_strjoin(TMP_FILE, node->param[0]);
	fd = open(name, O_CREAT | O_RDWR | O_TRUNC, 0644);
	str = readline(PS2);
	while (str && ft_strcmp(str, node->param[0]))
	{
		if (!ft_strcmp(node->exd_p[0], "1"))
			expand_heredoc_variable(str, fd);
		else
			write(fd, str, ft_strlen(str));
		write(fd, "\n", 1);
		free(str);
		str = readline(PS2);
	}
	close(fd);
	free(str);
	free(name);
}

void	open_heredoc_files(t_node *node)
{
	t_node	*tmp;

	tmp = node;
	while (tmp->type != NODE_EOF)
	{
		if (tmp->type == NODE_HEREDOC)
			write_inside_heredoc(tmp);
		tmp = tmp->next;
	}
}
