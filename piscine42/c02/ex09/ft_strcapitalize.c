/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoliiny <maoliiny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 09:32:46 by maoliiny          #+#    #+#             */
/*   Updated: 2025/02/23 18:38:44 by maoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int		i;
	int		new_word;

	i = 0;
	new_word = 1;
	while (str[i])
	{
		if (new_word && str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		else if (!new_word && str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		if (!(str[i] >= 'a' && str[i] <= 'z')
			&& !(str[i] >= 'A' && str[i] <= 'Z')
			&& !(str[i] >= '0' && str[i] <= '9'))
			new_word = 1;
		else
			new_word = 0;
		i++;
	}
	return (str);
}
