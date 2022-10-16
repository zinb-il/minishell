/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:36:26 by ibentour          #+#    #+#             */
/*   Updated: 2022/10/16 22:47:06 by ziloughm         ###   ########.fr       */
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
void		ft_print_export_line(t_env	*tmp, int out);
void		print_export_error(char	*s);
void		print_export(int out);
void		export_values(char *arg);
void		ft_export(char	**arg, int out);

int			ft_echo(char **args, int out);
void		ft_pwd(int out);
int			ft_env(int out);
void		ft_cd(char	**arg, int out);
void		ft_unset(char **args);
void		ft_exit(char **args);

#	endif