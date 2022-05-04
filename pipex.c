/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniilvoronin <daniilvoronin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 20:19:49 by daniilvoron       #+#    #+#             */
/*   Updated: 2022/05/04 22:42:00 by daniilvoron      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	multypipe(t_pipex_arg info)
{
	int		**fd;
	pid_t	*pid;
	int		i;

	i = 0;
	fd = make_fd(info);
	pid = malloc(sizeof(pid_t *) * (info.ac - 3));
	if (!pid)
		exit(EXIT_FAILURE);
	return (0);
	pipex(info, fd, pid);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex_arg	info;

	info.ac = argc;
	info.av = argv;
	info.envp = envp;
	multypipe(info);
	return (0);
}
