/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoliiny <maoliiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 08:37:24 by maoliiny          #+#    #+#             */
/*   Updated: 2025/02/26 09:14:16 by maoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	long long int	num;
	long long int	dd;
	long long int	temp_num;
	char			c;

	num = (long long int)nb;
	if (nb < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	dd = 1;
	temp_num = num;
	while (temp_num / 10 > 0)
	{
		dd *= 10;
		temp_num /= 10;
	}
	while (dd)
	{
		c = (num / dd) % 10 + '0';
		write(1, &c, 1);
		dd /= 10;
	}
}
