/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprester <cprester@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:25:24 by cprester          #+#    #+#             */
/*   Updated: 2022/05/04 18:00:47 by cprester         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*search_path(char **envp)
{
	char	*str;
	int		i;

	str = "PATH=";
	i = 0;
	while (envp != NULL)
	{
		if (ft_strncmp(envp[i], str, 5) == 0)
			return (&(envp[i][5]));
		i++;
	}
	return (NULL);
}

void	err_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(STDERR_FILENO, &str[i], 1);
		i++;
	}
	write(STDERR_FILENO, "/n", 1);
}

void	right_path(char **my_path, char **cmd, char **envp)
{
	int		i;
	char	*path_cmd;

	i = 0;
	while (my_path[i] != NULL)
	{
		path_cmd = ft_strjoin(my_path[i], "/");
		path_cmd = ft_strjoin(path_cmd, cmd[0]);
		if (access(path_cmd, F_OK) == 0)
		{
			execve(path_cmd, cmd, envp);
			write(STDERR_FILENO, "Execve failed", 13);
			exit(EXIT_FAILURE);
		}
		free(path_cmd);
		i++;
	}
	write (STDERR_FILENO, "pipex", 7);
	write (STDERR_FILENO, "comman not found", 19);
	err_putstr(cmd[0]);
	exit(EXIT_FAILURE);
}

char	*data_processing(char **argv, char **envp, int argv_numb)
{
	char	*path_envp;
	char	**my_path;
	char	**cmd;
	int		i;

	i = 0;
	if (argv[argv_numb][0] == '/')
	{
		cmd = ft_split(argv[argv_numb], ' ');
		execve(cmd[0], cmd, envp);
	}
	path_envp = search_path(envp);
	my_path = ft_split(path_envp, ':');
	cmd = ft_split(argv[argv_numb], ' ');
	right_path(my_path, cmd, envp);
	return (NULL);
}
