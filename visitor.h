/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visitor.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 23:59:40 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/21 15:17:01 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef VISITOR_H
# define VISITOR_H

//Expand redirections
void	joind_str(char **s1, char *s2);
int		env_redirection(char	*str, char **s1, int i);
int		d_quotes_redirection(char	*str, char **s1, int i);
int		s_quotes_redirection(char	*str, char **s1, int i);
char	*trim_str(char *str);
char	*char_redirection(char	*str);
void	add_expanded_toparam(t_node **node, char *str);
void	expanded_rediretions(t_node *node);

//Ambiguous redirections test
char	*clean_the_str(char	*str);
int		test_ambiguous(char	*str);

//WildCards matching
void	free_mat(int **mat, int m);
int		**init_matrix(int m, int n);
char	*find_patern(char *param);
char	**new_expand_param(char **param, char *str, char *str1);
void	check_if_added_elemnt(char ***list, int i, char *s1, t_node **node);
int		wild_card_matching(char *patern, char *str, int n, int m);
void	ft_opendir(t_node **node, char *s, int i, char ***list);
int		check_inlist_expand(t_node *node);
char	**expand_wildcards(t_node **node);
void	wild_card(t_node *node);

//Herdoce Files
void	ft_join_env_str(char **str3, char *str2);
int		herdoc_env_val(char *str, int i, char **str3);
void	expand_heredoc_variable(char *str, int fd);
int		count_herdoc(t_node *node);
int		fork_for_herdoc(int fd, t_node *node);
void	write_inside_heredoc(t_node *node, int i);
int		open_heredoc_files(t_node *node);

//Create output files
void	creat_output_files(t_node *node);

#	endif