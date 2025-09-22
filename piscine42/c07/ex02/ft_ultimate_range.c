/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoliiny <maoliiny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 10:29:34 by maoliiny          #+#    #+#             */
/*   Updated: 2025/03/02 19:24:22 by maoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	index;
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = (int *)malloc((max - min) * 4);
	if (*range == NULL)
		return (-1);
	index = 0;
	i = min;
	while (i < max)
	{
		(*range)[index] = i;
		i++;
		index++;
	}
	return (max - min);
}
