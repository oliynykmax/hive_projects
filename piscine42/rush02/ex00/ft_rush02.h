/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush02.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoliiny <maoliiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:38:16 by maoliiny          #+#    #+#             */
/*   Updated: 2025/03/09 20:14:22 by maoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RUSH02_H
# define FT_RUSH02_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct dicts
{
	unsigned __int128	num;
	char				*text;
}	t_dict;
typedef unsigned __int128	t_sh;
char				**ft_split(char *str, char *charset);
void				ft_putnbr(unsigned __int128 num, t_dict *tab);
t_dict				*ft_tab(char **tab_d);
void				ft_putstr(char *str, int index);
unsigned __int128	ft_atoi(char *str);

#endif
