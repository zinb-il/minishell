/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visito_herdoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:53:07 by ziloughm          #+#    #+#             */
/*   Updated: 2022/09/28 13:38:15 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	open_heredoc_files(t_node *node)
{
	t_node	*tmp;
	char	*str;
	char	*name;
	int		op;

	tmp = node;
	while (tmp->type != NODE_EOF)
	{
		if (tmp->type == NODE_HEREDOC)
		{
			name = ft_strjoin(TMP_FILE, tmp->param[0]);
			op = open(name, O_CREAT | O_RDWR | O_TRUNC, 0644);
			str = readline(PS2);
			while (str && ft_strcmp(str, tmp->param[0]))
			{
				write(op, str, ft_strlen(str));
				write(op, "\n", 1);
				free(str);
				str = readline(PS2);
			}
			close(op);
			free(str);
			free(name);
		}
		tmp = tmp->next;
	}
}
