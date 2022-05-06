/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniilvoronin <daniilvoronin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 20:19:49 by daniilvoron       #+#    #+#             */
/*   Updated: 2022/05/06 13:48:10 by daniilvoron      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_input_fork(int *fd, char **path, char **envp, int *pid)
{
	char	**envpaths;
	int 	i;
	char	*cmd;

	cmd = path[0];
	i = 0;
	*pid = fork();
	if (*pid < 0)
		exit(0);
	else if (*pid == 0)
	{
		dup2(fd[1], 1);
		dup2(fd[2], 0);
		close(fd[0]);
		close(fd[1]);
		close(fd[2]);
		close(fd[3]);
		envpaths = find_path(envp);
		while (envpaths[i] != NULL)
		{
			envpaths[i] = ft_strjoin(envpaths[i], "/");
			path[0] = ft_strjoin(envpaths[i], cmd);
			execve(path[0], path, envp);
			i++;
		}
		exit(0);
	}
}

void	handle_output_fork(int *fd, char **path, char **envp, int *pid)
{
	char	**envpaths;
	int 	i;
	char	*cmd;

	cmd = path[0];
	i = 0;
	*pid = fork();
	if (*pid < 0)
		exit(0);
	else if (*pid == 0)
	{
		dup2(fd[0], 0);
		dup2(fd[3], 1);
		close(fd[0]);
		close(fd[1]);
		close(fd[2]);
		close(fd[3]);
		envpaths = find_path(envp);
		while (envpaths[i] != NULL)
		{
			envpaths[i] = ft_strjoin(envpaths[i], "/");
			path[0] = ft_strjoin(envpaths[i], cmd);
			execve(path[0], path, envp);
			i++;
		}
		exit(0);
	}
}

int	handle_pipe(int *fd, char **argv, char **envp, pid_t *pid)
{
	char	**path;
	int		ret;

	ret = pipe(fd);
	if (ret < 0)
	{
		perror(strerror(ret));
		return (-1);
	}
	path = ft_split(argv[2], ' ');
	handle_input_fork(fd, path, envp, &(pid[0]));
	free_path(path);
	path = ft_split(argv[3], ' ');
	handle_output_fork(fd, path, envp, &(pid[1]));
	free_path(path);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[4];
	pid_t	pid[2];

	if (argc != 5)
	{
		write(2, "Error! Wrong arguments!\n", 24);
		return (-1);
	}
	fd[2] = open(argv[1], O_RDONLY);
	fd[3] = open(argv[4], O_CREAT | O_RDWR, 0644);
	handle_pipe(fd, argv, envp, pid);
	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
	close(fd[3]);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
	return (0);
}
