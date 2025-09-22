/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoliiny <maoliiny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:54:08 by maoliiny          #+#    #+#             */
/*   Updated: 2025/05/20 18:53:43 by maoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	char	**cmd;
	char	**file;
}			t_args;

void	free_ft_split(char **tab);
void	cleanup(char **args, char *cmd_path, char *msg);
void	ft_error(char *str);
char	**split_path(char **ep);

#endif
