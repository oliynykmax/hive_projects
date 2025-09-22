/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoliiny <maoliiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:32:34 by maoliiny          #+#    #+#             */
/*   Updated: 2025/03/09 21:09:36 by maoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

void	ft_putstr(char *str, int index)
{
	while (*str)
		write(1, str++, 1);
	if (index != 1)
		write(1, " ", 1);
}

unsigned __int128	ft_atoi(char *str)
{
	unsigned __int128	number;
	int					i;
	int					minus;

	i = 0;
	number = 0;
	minus = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			write(2, "Error\n", 6);
			return (1);
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		number = number * 10 + (str[i++] - '0');
	return (number);
}

char	**reading(unsigned __int128 fd)
{
	char	*buf;
	char	**fint;

	buf = malloc(1500);
	read(fd, buf, 1500);
	fint = ft_split(buf, "\n");
	return (fint);
}

int	error_check(int argc)
{
	if (argc < 2 || argc > 3)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	unsigned __int128	num;
	int					fd;
	char				**tab;
	t_dict				*shit;

	if (error_check(ac) == 1)
		return (1);
	num = ft_atoi(av[1]);
	if (ac == 2)
		fd = open("numbers.dict", O_RDONLY);
	else
		fd = open(av[2], O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	tab = reading(fd);
	shit = ft_tab(tab);
	ft_putnbr(num, shit);
	write(1, "\n", 1);
	close(fd);
	return (0);
}
