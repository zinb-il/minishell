/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 15:54:19 by ziloughm          #+#    #+#             */
/*   Updated: 2022/09/29 21:56:24 by ziloughm         ###   ########.fr       */
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
	char			**exd_p;
	struct s_node	*prev;
	struct s_node	*next;
}t_node;

//Get nodes
t_node	*init_node(int type, char *value);
t_node	*get_last_node(t_node *node);
void	add_last_node(t_node **nodes, t_node *node);
void	print_nodess(t_node *nodes);
void	free_nodes(t_node *nodes);
void	get_node_param(t_node **node, t_token *token);
void	check_if_expand(t_node **node, t_token *token);
t_node	*advs_node(t_token **token, t_node *node);
t_node	*get_node_wored_cmd(t_token **token);
t_node	*get_node_wored_herdoc(t_token **token);
t_node	*get_next_node_wored(t_token **token);
t_node	*get_next_node(t_token **token);
t_node	*get_nodes(t_token *token);
#	endif