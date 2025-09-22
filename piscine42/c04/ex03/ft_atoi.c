/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoliiny <maoliiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 09:15:57 by maoliiny          #+#    #+#             */
/*   Updated: 2025/03/02 09:46:37 by maoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_whitespace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_atoi(char *str)
{
	int	number;
	int	i;
	int	minus;

	i = 0;
	number = 0;
	minus = 1;
	while (is_whitespace(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			minus = -minus;
		}
		i++;
	}
	while (is_digit(str[i]))
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	return (minus * number);
}
