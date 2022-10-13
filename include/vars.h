/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibentour <ibentour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 18:40:52 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/09 20:58:05 by ibentour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef VARS_H
# define VARS_H

//Prompt String
# define PS1 "\033[0;32mminishell-1.0:~$\033[0;37m "
# define PS2 "> "
# define ERR_SYN "syntax error near unexpected token near "
# define ERR_EXEC "\033[0;31mminishell:\033[0;37m "

//Special characters
# define SPCL "&<>$|\'()\"\t "
# define SPCL1 "<>$|\' \"\t"
# define SPCL2 "&<>$|\' \"\t"
# define SPCL3 "$()<>|\' \"\t"

//Heredoce Nmefile
# define TMP_FILE "heredoc_tmp_file_"

//Elements
typedef struct s_env
{
	char			*env_att;
	char			*env_val;
	struct s_env	*next;
}t_env;

typedef struct s_vars
{
	int			exit_code;
	int			sign;
	pid_t		process_pid;
	pid_t		child_process_pid;
	char		**herdo_files;
	t_env		*env;
}t_vars;

t_vars	g_vars;

t_env	*ft_lstnew(char *name, char *value);
int		ft_lstsize(t_env *lst);
void	ft_lstadd_back(t_env **lst, t_env *new);
void	ft_lstadd_front(t_env **lst, t_env *new);
t_env	*ft_lstlast(t_env *lst);

#	endif
