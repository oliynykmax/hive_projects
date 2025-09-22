/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoliiny <maoliiny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:53:33 by maoliiny          #+#    #+#             */
/*   Updated: 2025/04/30 20:53:50 by maoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf_c(char c);
int		choose_type(va_list *args, const char **s);
int		ft_printf_s(char *s);
int		ft_printf_diux(long un, char *base);
size_t	ft_strlen(const char *s);
int		write_reverse(const char *buffer, int len);
int		ft_printf_pnum(unsigned long long un, char *base);
int		ft_printf(const char *s, ...);
int		ft_printf_p(void *ptr);

#endif
