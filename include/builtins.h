/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibentour <ibentour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:36:26 by ibentour          #+#    #+#             */
/*   Updated: 2022/10/15 10:25:28 by ibentour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef BUILTINS_H
# define BUILTINS_H

typedef struct s_builtins
{
	int			a;
	int			b;
	int			i;
	int			j;
	int			ac;
	t_env		*tmp;
	char		*val_p;
	char		*old_pwd;
	char		*new_opwd;
	char		*tmp_o;
	char		*to_export[2];
	int			n_line;
}	t_builtins;

//Export functions
int			check_chars(char *arg);
char		**find_first_ecl(char *arg);
int			env_exists(char *arg);
void		print_export(void);
void		export_values(char *arg);
void		ft_export(char	**arg);

int			ft_echo(char **args);
void		ft_pwd(void);
int			ft_env(void);
void		ft_cd(char	**arg);
void		ft_unset(char **args);
void		ft_exit(char **args);

#	endif
