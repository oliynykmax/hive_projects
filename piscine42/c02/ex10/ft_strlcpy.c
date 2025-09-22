/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoliiny <maoliiny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 11:35:28 by maoliiny          #+#    #+#             */
/*   Updated: 2025/02/23 13:46:04 by maoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int	j;
	int	i;
	int	counter;

	i = 0;
	j = size;
	counter = 0;
	while (src[counter] != '\0')
		counter++;
	if (size > 0)
	{
		while (src[i] != '\0' && i < j -1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (counter);
}
