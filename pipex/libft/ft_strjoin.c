/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoliiny <maoliiny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:00:50 by maoliiny          #+#    #+#             */
/*   Updated: 2025/05/20 13:25:41 by maoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strjoin_trio(char const *s1, char const *s2, char const *s3)
{
	size_t	len1;
	size_t	len2;
	size_t	len3;
	size_t	total_len;
	char	*result;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	len3 = ft_strlen(s3);
	total_len = len1 + len2 + len3 + 1;
	result = malloc(total_len * sizeof(char));
	if (!result)
		return (NULL);
	ft_memcpy(result, s1, len1);
	ft_memcpy(result + len1, s2, len2);
	ft_memcpy(result + len1 + len2, s3, len3);
	result[total_len - 1] = '\0';
	return (result);
}
