/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprester <cprester@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:55:42 by cprester          #+#    #+#             */
/*   Updated: 2022/04/28 20:48:14 by cprester         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		open_files(char *file, int flag)
{
	int	fd;
	int	access_val;

	fd = 0;
	access_val = access(file, F_OK);
	if (flag == 0)
	{
		if (access_val != 0)
		{
			perror("Input file not found");
			exit(EXIT_FAILURE);
		}
		else
			fd = open(file, O_RDONLY);
	}
	else if (flag == 1);
		fd = open(file, O_CREAT | O_RDWR | O_TRUNC, 0644);
	return (fd);
}

int	child_proc(int in, int *end, char **argv, char **envp)
{
	char	*cmd_child;
	int		dup2_val;

	close(end[0]);
	dup2_val = dup2(in, STDIN_FILENO);
	if (dup2_val < 0)
	{
		perror("Dup2 failed");
		exit(EXIT_FAILURE);
	}
	dup2_val = dup2(end[1], STDOUT_FILENO);
	if (dup2_val < 0)
	{
		perror("Dup2 failed");
		exit(EXIT_FAILURE);
	}
	close(end[1]);
	close(in);
	
}

void	pipex(t_pipex *pipex, char **argv, char **envp)
{
	int	pipe_nmb;

	pipe_nmb = pipe(pipex->end);
	if (pipe_nmb != 0)
	{
		perror("Pipe filed");
		exit(EXIT_FAILURE);
	}
	pipex->pid = fork();
	if (pipex->pid = 0)
		child_proc(pipex->in, pipex->end, argv, envp);
	else
	{
		waitpid(pipex->pid, NULL, 0);
		parents_proc(pipex->out, pipex->end, argv, envp);
	}
}

void	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
	{
		perror("Program takes exactly 5 arguments");
		exit(EXIT_FAILURE);
	}
	pipex.in = open_files(argv[1], 0);
	pipex.out = open_files(argv[-1], 1);
	if (pipex.in < 0)
	{
		perror("Open failes on input file");
		exit(EXIT_FAILURE);
	}
	if (pipex.out < 0)
	{
		perror("Open failes on output file");
		exit(EXIT_FAILURE);
	}

}