/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_processing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoliiny <maoliiny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:27:00 by maoliiny          #+#    #+#             */
/*   Updated: 2025/03/09 18:29:54 by maoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

unsigned __int128	take_num(char *str)
{
	unsigned __int128	dest;
	unsigned __int128	len;

	len = 0;
	while (str[len])
		len++;
	dest = ft_atoi(str);
	return (dest);
}

char	*take_txt(char *str)
{
	char	*dest;
	int		i;
	int		len;
	int		j;

	j = 0;
	i = 0;
	len = 0;
	while (str[len])
		len++;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	while (!(str[i] == ':'))
		i++;
	i++;
	while (str[i] == ' ')
		i++;
	while (str[i] >= 32 && str[i] <= 126)
	{
		dest[j] = str[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

t_dict	*ft_tab(char **tab_d)
{
	t_dict		*tab;
	int			i;
	int			a;

	a = 0;
	while (tab_d[a] != 0)
		a++;
	tab = malloc((a + 1) * sizeof(t_dict));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (tab_d[i] != 0)
	{
		tab[i].num = take_num(tab_d[i]);
		tab[i].text = take_txt(tab_d[i]);
		i++;
	}
	tab[a].text = 0;
	return (tab);
}
