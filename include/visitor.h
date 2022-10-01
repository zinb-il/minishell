/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visitor.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 23:59:40 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/01 23:55:44 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef VISITOR_H
# define VISITOR_H

void	free_mat(int **mat, int m);
int		**init_matrix(int m, int n);
char	*find_patern(char *param);
char	**new_expand_param(char **param, char *str);
void	open_heredoc_files(t_node *node);
void	wild_card(t_node *node);

#	endif