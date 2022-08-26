/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 18:40:52 by ziloughm          #+#    #+#             */
/*   Updated: 2022/08/26 14:14:34 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef VARS_H
# define VARS_H

//Prompt String
# define PS1 "\033[0;32m minishell:~$\033[0;37m "
# define PS2 "> "

//Elements
typedef struct s_env
{
	char			*env_att;
	char			*env_val;
	struct s_env	*next;
}t_env;

typedef struct s_local_var
{
	char				*var_att;
	char				*var_val;
	struct s_local_var	*next;
}t_local_var;

typedef struct s_vars
{
	int			exit_code;
	pid_t		process_pid;
	t_env		*env;
	t_local_var	*local_var;
}t_vars;

t_vars	g_vars;

#	endif