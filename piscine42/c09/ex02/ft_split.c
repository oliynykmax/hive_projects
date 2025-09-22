/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoliiny <maoliiny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:27:27 by maoliiny          #+#    #+#             */
/*   Updated: 2025/03/05 20:44:02 by maoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strchr(char c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strdup(char *src, int n)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc((n + 1));
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_sp(char *str, char *charset, char **tab)
{
	int	start;
	int	counter;
	int	i;

	counter = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && ft_strchr(str[i], charset))
			i++;
		start = i;
		while (!ft_strchr(str[i], charset) && str[i])
			i++;
		if (tab && start < i)
			tab[counter] = ft_strdup(&str[start], i - start);
		if (start < i)
			counter++;
	}
	return (counter);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		i;

	tab = malloc(sizeof(char *) * (ft_sp(str, charset, NULL) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	i = ft_sp(str, charset, NULL);
	ft_sp(str, charset, tab);
	tab[i] = 0;
	return (tab);
}

/*#include <stdio.h>
#include <string.h>

int main(void) {
	char *str = "Hello,I;am*bee";
	char *sep = ",;*";
	int i = 0;
	char **fint = ft_split(str, sep);
	while (fint[i] != 0)
	{
		printf("%s ", fint[i]);
		i++;
	}
	free(fint);
	return (0);
}*/
