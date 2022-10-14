/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:11:11 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/06 22:26:31 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef EXECUTION_H
# define EXECUTION_H

//Util function
int		ft_lstsizecmd(t_cmd *lst);
void	ft_error(char *msg, int i);
int		check_inlist_builtin(char *s);
int		ft_chekc_inputfile(char *str);
int		ft_chekc_ouputfile(char *str, int app);
char	*ft_check_path_exist(void);
char	**ft_get_path(void);
int		ft_en_len(void);
char	**ft_get_env(void);
void	ft_exe_cmd(char	*cmd, char **param, char **env);
char	**add_param(char **p, char	*str);
void	ft_execute_cmd(t_cmd *line_cmd);

//Bultins execution functions 
int		check_builtin(char *builtin);
void	execute_builtin(int x, char **ast_args);

//Util Execute Command
void	ft_execute_cmd(t_cmd *line_cmd);

//Execut Command Line
void	ft_execute_single_cmd(t_cmd *line_cmd);
void	ft_execute_cmd_line(t_cmd *line_cmd);

void	second_part(t_ast *ast);

#	endif