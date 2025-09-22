/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoliiny <maoliiny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:14:04 by maoliiny          #+#    #+#             */
/*   Updated: 2025/03/02 10:27:11 by maoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	i;
	int	index;

	if (min >= max)
		return (NULL);
	range = (int *)malloc((max - min) * 4);
	index = 0;
	i = min;
	while (i < max)
	{
		range[index] = i;
		i++;
		index++;
	}
	return (range);
}
