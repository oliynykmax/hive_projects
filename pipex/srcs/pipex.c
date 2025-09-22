/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoliiny <maoliiny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:53:56 by maoliiny          #+#    #+#             */
/*   Updated: 2025/05/20 19:01:46 by maoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

static char	*get_cmd_path(char *cmd, char **ep)
{
	char	**options;
	char	*full_path;
	int		i;

	options = split_path(ep);
	if (options == NULL)
		return (NULL);
	i = 0;
	while (options[i] != NULL)
	{
		full_path = ft_strjoin_trio(options[i], "/", cmd);
		if (full_path == NULL)
			break ;
		if (access(full_path, F_OK | X_OK) == 0)
		{
			free_ft_split(options);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	free_ft_split(options);
	return (NULL);
}

static void	exit_cmd_not_found(char *cmd, int fd_out, char **args)
{
	if (fd_out >= 0)
		close(fd_out);
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
	free_ft_split(args);
	exit(127);
}

static void	do_parent(char **av, char **ep, int pipe_fd[2])
{
	int		outfile;
	char	**args;
	char	*cmd_path;

	outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
		cleanup(NULL, NULL, "No such file or directory");
	args = ft_split(av[3], ' ');
	if (!args)
		cleanup(NULL, NULL, "memory allocation failed");
	cmd_path = get_cmd_path(args[0], ep);
	if (!cmd_path)
		exit_cmd_not_found(args[0], outfile, args);
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	execve(cmd_path, args, ep);
	cleanup(args, cmd_path, "execve failed");
}

static void	do_child(char **av, char **ep, int *pipe_fd)
{
	int		fd;
	char	**args;
	char	*cmd_path;

	args = ft_split(av[2], ' ');
	if (!args)
		cleanup(NULL, NULL, "memory allocation failed");
	cmd_path = get_cmd_path(args[0], ep);
	if (cmd_path == NULL)
		cleanup(args, NULL, "command not found");
	if (access(av[1], F_OK) == 0)
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
			cleanup(args, cmd_path, "permission denied");
		dup2(fd, STDIN_FILENO);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(fd);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		execve(cmd_path, args, ep);
		cleanup(args, cmd_path, "execve failed");
	}
	cleanup(args, cmd_path, "No such file or directory");
}

int	main(int ac, char **av, char **ep)
{
	pid_t	pid[2];
	int		pipe_fd[2];
	int		status[2];

	if (ac != 5)
		ft_error("Invalid input\nEx: ./pipex file1 cmd1 cmd2 file2\n");
	if (pipe(pipe_fd) < 0)
		ft_error("pipe creation failed");
	pid[0] = fork();
	if (pid[0] < 0)
		ft_error("forking failed");
	if (pid[0] == 0)
		do_child(av, ep, pipe_fd);
	pid[1] = fork();
	if (pid[1] < 0)
		ft_error("fork failed");
	if (pid[1] == 0)
		do_parent(av, ep, pipe_fd);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid[0], &(status[0]), 0);
	waitpid(pid[1], &(status[1]), 0);
	if (WIFEXITED(status[1]))
		return (WEXITSTATUS(status[1]));
	return (EXIT_FAILURE);
}
