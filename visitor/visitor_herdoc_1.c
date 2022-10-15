/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visitor_herdoc_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:53:07 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/15 23:10:03 by ziloughm         ###   ########.fr       */
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

void	write_inside_heredoc(t_node *node, int i)
{
	char	*name;
	int		fd;
	int		statut;
	int		pid;
	char	*str;

	str = ft_itoa(i);
	name = ft_strjoin(TMP_FILE, str);
	free(str);
	fd = open(name, O_CREAT | O_RDWR | O_TRUNC, 0644);
	add_herdo_name(name);
	pid = fork_for_herdoc(fd, node);
	waitpid(pid, &statut, 0);
	if (WIFEXITED(statut))
		g_vars.exit_code = WEXITSTATUS(statut);
	signals(0);
	close(fd);
	free(node->param[0]);
	node->param[0] = name;
}

void	open_heredoc_files(t_node *node)
{
	t_node	*tmp;
	int		i;

	tmp = node;
	i = 0;
	while (tmp->type != NODE_EOF)
	{
		if (tmp->type == NODE_HEREDOC)
			write_inside_heredoc(tmp, i);
		tmp = tmp->next;
		i++;
	}
}
