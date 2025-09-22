/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoliiny <maoliiny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:01:54 by maoliiny          #+#    #+#             */
/*   Updated: 2025/02/19 19:57:56 by maoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

void	ft_print_alphabet(void)
{
	char	letter;
	int		i;

	i = 0;
	while (i < 26)
	{
		letter = 'a' + i;
		write(1, &letter, 1);
		i = i + 1;
	}
}
