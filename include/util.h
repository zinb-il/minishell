/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 18:35:53 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/16 21:27:03 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef UTIL_H
# define UTIL_H

//GLOBAL ENV functions
t_env	*ft_getlast_env(t_env *lst);
void	ft_addlast_env(t_env **lst, t_env *new);
t_env	*get_env_elmnt(char *line);
void	get_env(char **env);
char	*get_env_val(t_env *env, char *var);
void	free_env(t_env *env);
void	free_single_env(t_env **env);
void	free_dstr(char	**str);

//Init Our minishell
void	init_minishell(char **env);

//Readline function
int		str_redline(char *str);

//Display new prompt
void	get_new_promt(char *str);

//Heredoc functions
void	add_herdo_name(char	*str);
void	unlik_herdo_name(void);

#	endif