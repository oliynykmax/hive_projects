/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoliiny <maoliiny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:37:45 by maoliiny          #+#    #+#             */
/*   Updated: 2025/03/11 15:54:45 by maoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int	counter;
	int	i;

	counter = 0;
	i = 0;
	while (i < length)
	{
		if (f(tab[i]))
			++counter;
		++i;
	}
	return (counter);
}
