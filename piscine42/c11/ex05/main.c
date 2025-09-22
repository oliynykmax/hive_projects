/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoliiny <maoliiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:42:28 by maoliiny          #+#    #+#             */
/*   Updated: 2025/03/12 22:08:53 by maoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str);

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

int	is_valid_op(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i > 1)
		return (1);
	if (!(str[0] == '+' || str[0] == '-'
			|| str[0] == '*' || str[0] == '%' || str[0] == '/'))
		return (1);
	else
		return (0);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

void	ft_operation(int a, int b, char op)
{
	int	num;

	num = 23;
	if (op == '+')
		num = a + b;
	if (op == '-')
		num = a - b;
	if (op == '*')
		num = a * b;
	if (op == '/')
		num = a / b;
	if (op == '%')
		num = a % b;
	ft_putnbr(num);
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int		v1;
	int		v2;
	char	op;

	if (argc != 4)
		return (0);
	if (is_valid_op(argv[2]))
	{
		ft_putstr("0");
		return (0);
	}
	op = argv[2][0];
	v1 = ft_atoi(argv[1]);
	v2 = ft_atoi(argv[3]);
	if ((argv[2][0] == '%') && v2 == 0)
		ft_putstr("Stop : modulo by zero");
	else if ((argv[2][0] == '/') && v2 == 0)
		ft_putstr("Stop : division by zero");
	else
		ft_operation(v1, v2, op);
	return (0);
}
