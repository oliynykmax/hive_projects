/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoliiny <maoliiny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:08:30 by maoliiny          #+#    #+#             */
/*   Updated: 2025/02/20 12:24:59 by maoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*used standart letters for loops, different names for digits, 
needed to split the solution*/
void	ft_write_number(int a, int b, int c)
{
	char	digit1;
	char	digit2;
	char	digit3;

	digit1 = a + '0';
	digit2 = b + '0';
	digit3 = c + '0';
	write(1, &digit1, 1);
	write(1, &digit2, 1);
	write(1, &digit3, 1);
	if (!(a == 7 && b == 8 && c == 9))
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i <= 9)
	{
		j = i + 1;
		while (j <= 9)
		{
			k = j + 1;
			while (k <= 9)
			{
				ft_write_number(i, j, k);
				k++;
			}
			j++;
		}
		i++;
	}
}
