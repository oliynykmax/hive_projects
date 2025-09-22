/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoliiny <maoliiny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:17:19 by maoliiny          #+#    #+#             */
/*   Updated: 2025/02/27 11:59:38 by maoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	int	num;
	int	counter;

	num = 2;
	counter = 0;
	if (nb <= 1)
		return (2);
	while (num * num <= nb)
	{
		if (nb % num == 0)
			counter = 1;
		num++;
	}
	if (counter == 0)
		return (nb);
	return (ft_find_next_prime(nb + 1));
}
