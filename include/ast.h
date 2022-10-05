/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 23:28:22 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/04 22:03:24 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef AST_H
# define AST_H

typedef enum e_ast_type
{
	AST_CMDLINE,
	AST_LPARENTH,
	AST_RPARENTH,
	AST_DAND,
	AST_DOR,
	AST_EOF
}t_ast_type;

typedef struct s_cmd
{
	char			*value;
	char			**param;
	char			*input;
	char			*output;
	int				append;
	struct s_cmd	*next;
}t_cmd;

typedef struct s_ast
{
	t_ast_type		type;
	t_cmd			*line_cmd;
	struct s_ast	*next;
}t_ast;

//CMD Function
t_cmd	*init_cmd(void);
t_cmd	*last_cmd(t_cmd *cmd);
void	add_cmd(t_cmd **cmd, t_cmd *new_cmd);
void	free_cmd(t_cmd *cmd);
void	print_cmd(t_cmd *cmd);

//AST Function
t_ast	*init_ast(int type, t_cmd *cmd);
t_ast	*last_ast(t_ast *ast);
void	add_ast(t_ast **ast, t_ast *new_ast);
void	free_ast(t_ast *ast);
void	print_ast(t_ast *ast);
t_ast	*advs_ast(t_node **node, t_ast *ast);
t_ast	*get_next_ast(t_node **node);
char	**ft_strdup_d(char	**param);
int		not_other_ast(t_node **node);
void	free_oldin_out(char	**str1, char *str2);
t_cmd	*get_next_cmd(t_node **node);
t_cmd	*get_cmd_line(t_node **node);
t_ast	*get_ast(t_node *node);

#	endif