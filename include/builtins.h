/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:36:26 by ibentour          #+#    #+#             */
/*   Updated: 2022/10/14 00:29:42 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef BUILTINS_H
# define BUILTINS_H

typedef struct s_builtins
{
	int		a;
	int		b;
	int		i;
	int		j;
	int		ac;
	int		n_line;

}	t_builtins;

//Echo functions
int			ft_echo(char **args);

//Export functions
int			check_chars(char *arg);
char		**find_first_ecl(char *arg, char ecl);
int			env_exists(char *arg);
void		print_export(void);
void		export_values(char *arg);
void		ft_export(char	**arg);

int			ft_env(void);
void		ft_pwd(void);

#	endif