/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoliiny <maoliiny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:10:13 by maoliiny          #+#    #+#             */
/*   Updated: 2025/05/20 18:50:07 by maoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

void	free_ft_split(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return ;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	cleanup(char **args, char *cmd_path, char *msg)
{
	free_ft_split(args);
	if (cmd_path != NULL)
		free(cmd_path);
	ft_error(msg);
}

void	ft_error(char *str)
{
	int	i;

	ft_putstr_fd("pipex: ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	i = ft_strlen(str);
	if (i != 0)
		if (str[i - 1] != '\n')
			ft_putchar_fd('\n', STDERR_FILENO);
	exit(EXIT_FAILURE);
}

char	**split_path(char **ep)
{
	while (*ep && strncmp(*ep, "PATH=", 5))
		ep++;
	if (!*ep)
		return (NULL);
	return (ft_split(*ep + 5, ':'));
}
