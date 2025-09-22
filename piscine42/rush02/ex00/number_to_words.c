/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_to_words.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoliiny <maoliiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:20:25 by maoliiny          #+#    #+#             */
/*   Updated: 2025/03/09 20:16:42 by maoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

char	*i_c_s(unsigned __int128 c, t_dict *tab)
{
	int	i;

	i = 0;
	while (tab[i].text != 0)
	{
		if (c == tab[i].num)
			return (tab[i].text);
		i++;
	}
	return ("Dict error\n");
}

unsigned __int128	ft_power(unsigned __int128 nb, __int128 power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power > 1)
		nb = nb * ft_power(nb, power - 1);
	return (nb);
}

void	print_d(int i, t_dict *tab, int buff[100], t_sh	div1)
{
	while (i > 0)
	{
		div1 = 2 + 3 * (i / 3);
		if (buff[i] != 0)
		{
			if (i % 3 == 0)
			{
				ft_putstr(i_c_s(buff[i], tab), i);
				ft_putstr(i_c_s(100, tab), i);
			}
			else if (i % div1 == 0 && buff[i] == 1)
			{
				ft_putstr(i_c_s((buff[i] * 10 + buff[i - 1]), tab), i);
				i--;
			}
			else if (i % div1 == 0 && buff[i] > 1)
				ft_putstr(i_c_s((buff[i] * 10), tab), i);
			else if (i % 3 != 0)
				ft_putstr(i_c_s(buff[i], tab), i);
		}
		if ((i - 1) % 3 == 0 && i > 2 && !(buff[i] == 0
				&& buff[i + 1] == 0 && buff[i + 2] == 0))
			ft_putstr(i_c_s(ft_power(10, (i - (i % 3))), tab), i);
		i--;
	}
}

void	ft_putnbr(unsigned __int128 num, t_dict *tab)
{
	int					index;
	int					buff[128];
	unsigned __int128	div1;

	div1 = 0;
	index = 1;
	buff[0] = 0;
	while (num > 0)
	{
		buff[index++] = num % 10;
		num = num / 10;
	}
	index--;
	print_d(index, tab, buff, div1);
}
