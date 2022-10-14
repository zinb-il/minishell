/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:20:51 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/06 22:25:10 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef LIBFT_H
# define LIBFT_H

int		ft_isalnum(int c);
int		ft_isalpha(int x);
char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);
size_t	ft_strsize(char **str);
int		ft_fndc(char *str, char c);
char	*ft_strrchr(const char *str, int c);
char	*ft_strrrchr(const char *str, int c);
void	ft_bzero(void *str, size_t n);
void	*ft_calloc(size_t n, size_t s);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcat(void *dest, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strcmp(const char *str1, const char *str2);
int		ft_strncmp(const char *str1, const char *str2, size_t n);

t_env	*ft_lstnew(char *name, char *value);
int		ft_lstsize(t_env *lst);
void	ft_lstadd_back(t_env **lst, t_env *new);
void	ft_lstadd_front(t_env **lst, t_env *new);
t_env	*ft_lstlast(t_env *lst);

#	endif