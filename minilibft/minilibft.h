/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibft.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 06:46:15 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/03/20 22:58:54 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBFT_H
# define MINILIBFT_H

// # include <string.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int		get_next_line(int fd, char **line);
int		ft_read_file(char **stock, int fd);
void	ft_fill_static(char **stock, char *buf);
int		ft_line_break(char *stock);
char	**ft_split(char const *s, char c);
int		ft_malloc_index(char **tab, char const *s, char c,
			unsigned int index);
int		ft_count_index(char const *s, char c);
void	ft_free_tab(char **tab);
int		ft_get_tab_size(char **tab);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
void	ft_putstr(char *s);
void	ft_putchar(char c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atoi(const char *s);
int		ft_isdigit(int c);
char	*ft_strtrim(char const *s1, char const *set);
int		ft_checkset(char c, const char *set);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif
