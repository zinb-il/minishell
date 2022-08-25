/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 18:35:53 by ziloughm          #+#    #+#             */
/*   Updated: 2022/08/22 20:03:27 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef UTIL_H
# define UTIL_H

t_env	*ft_getlast_env(t_env *lst);
void	ft_addlast_env(t_env **lst, t_env *new);
t_env	*get_env_elmnt(char *line);
void	get_env(char **env);

#	endif