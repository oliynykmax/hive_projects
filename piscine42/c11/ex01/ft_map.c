/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoliiny <maoliiny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:21:33 by maoliiny          #+#    #+#             */
/*   Updated: 2025/03/13 14:20:01 by maoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*arr;
	int	i;

	i = 0;
	arr = malloc(sizeof(int) * length);
	if (arr == NULL)
		return (NULL);
	while (i < length)
	{
		arr[i] = f(tab[i]);
		++i;
	}
	return (arr);
}
