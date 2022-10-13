/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibentour <ibentour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:36:26 by ibentour          #+#    #+#             */
/*   Updated: 2022/10/06 11:56:12 by ibentour         ###   ########.fr       */
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

int			ft_echo(char **args);
void		ft_export(char	**arg);
int			ft_env(void);
void		ft_pwd(void);

#	endif