/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibentour <ibentour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:20:51 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/11 22:14:17 by ibentour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef LIBFT_H
# define LIBFT_H

int		ft_isalnum(int c);
char	*ft_itoa(int n);
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
char	*ft_strjoin(char *s1, char *s2);
int		ft_strcmp(const char *str1, const char *str2);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_isalpha(int x);
#	endif