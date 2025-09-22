/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoliiny <maoliiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:55:55 by maoliiny          #+#    #+#             */
/*   Updated: 2025/03/02 09:55:04 by maoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	base_is_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

long long	minuss(long long num)
{
	if (num < 0)
	{
		ft_putchar('-');
		num = -num;
	}
	return (num);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			base_len;
	long long	num;
	char		buffer[50];
	int			buffer_index;

	base_len = 0;
	buffer_index = 0;
	if (!base_is_valid(base))
		return ;
	while (base[base_len] != '\0')
		base_len++;
	num = minuss((long long)nbr);
	if (num == 0)
	{
		ft_putchar(base[0]);
		return ;
	}
	while (num > 0)
	{
		buffer[buffer_index++] = base[num % base_len];
		num = num / base_len;
	}
	while (buffer_index > 0)
		ft_putchar(buffer[--buffer_index]);
}
