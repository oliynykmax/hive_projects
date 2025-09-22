/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoliiny <maoliiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:42:29 by maoliiny          #+#    #+#             */
/*   Updated: 2025/02/22 17:52:18 by maoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	rush(int width, int height)
{
	int	col;
	int	row;

	if (width <= 0 || height <= 0)
		return ;
	row = 1;
	while (row <= height)
	{
		col = 1;
		while (col <= width)
		{
			if ((row == 1 && col == 1) || (row == height && col == 1))
				ft_putchar('A');
			else if ((row == 1 && col == width)
				|| (row == height && col == width))
				ft_putchar('C');
			else if (row == 1 || row == height || col == 1 || col == width)
				ft_putchar('B');
			else
				ft_putchar(' ');
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}
