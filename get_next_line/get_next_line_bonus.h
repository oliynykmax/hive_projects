/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoliiny <maoliiny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:34:03 by maoliiny          #+#    #+#             */
/*   Updated: 2025/04/28 15:32:50 by maoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# ifndef FD_NUM
#  define FD_NUM 1024
# endif

# include <stdlib.h>
# include <unistd.h>

char	*ft_strncpy(const char *src, int n);
char	*extract_line(char **res);
char	*get_next_line(int fd);
int		ft_strchr(char *s, char c);
size_t	ft_strlen(const char *s);
int		ft_strcat(char **res, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif
