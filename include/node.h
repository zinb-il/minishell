/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 15:54:19 by ziloughm          #+#    #+#             */
/*   Updated: 2022/09/25 16:38:25 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef NODE_H
# define NODE_H

typedef enum e_node_type
{
	NODE_CMD,
	NODE_RED_OUT,
	NODE_RED_IN,
	NODE_RED_AOUT,
	NODE_HEREDOC,
	NODE_PIPE,
	NODE_DPIPE,
	NODE_EQUAL,
	NODE_DAND,
	NODE_LPARENTH,
	NODE_RPARENTH,
	NODE_EOF
}t_node_type;

typedef struct s_node
{
	t_node_type		type;
	char			*value;
	char			**param;
	struct s_node	*prev;
	struct s_node	*next;
}t_node;

//Get nodes
t_node	*init_node(int type, char *value);
t_node	*get_last_node(t_node *node);
void	add_last_node(t_node **nodes, t_node *node);
void	print_nodess(t_node *nodes);
void	free_nodes(t_node *nodes);
t_node	*get_nodes(t_token *token);
#	endif