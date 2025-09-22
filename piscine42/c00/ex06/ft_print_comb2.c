/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoliiny <maoliiny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:19:44 by maoliiny          #+#    #+#             */
/*   Updated: 2025/02/20 12:24:21 by maoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*similar approach to ft_print_comb*/
void	ft_write_number(int a, int b, int c, int d)
{
	char	digit1;
	char	digit2;
	char	digit3;
	char	digit4;

	digit1 = a + '0';
	digit2 = b + '0';
	digit3 = c + '0';
	digit4 = d + '0';
	write(1, &digit1, 1);
	write(1, &digit2, 1);
	write(1, " ", 1);
	write(1, &digit3, 1);
	write(1, &digit4, 1);
	if (!(a == 9 && b == 8 && c == 9 && d == 9))
	{
		write(1, ", ", 2);
	}
}

void	ft_number_loop(int a, int b)
{
	int		c;
	int		d;

	c = a;
	while (c <= 9)
	{
		d = b +1;
		while (d <= 9)
		{
			if (c >= a && d > b)
			{
				ft_write_number(a, b, c, d);
			}
			d++;
		}
		c++;
	}
}

void	ft_print_comb2(void)
{
	int		i;
	int		j;

	i = 0;
	while (i <= 9)
	{
		j = 0;
		while (j <= 9)
		{
			ft_number_loop(i, j);
			j++;
		}
		i++;
	}
}
