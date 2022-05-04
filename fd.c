/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniilvoronin <daniilvoronin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 22:17:52 by daniilvoron       #+#    #+#             */
/*   Updated: 2022/05/05 01:01:10 by daniilvoron      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	**make_fd(t_pipex_arg info)
{
	int	**fd;
	int	i;

	i = 0;
	fd = malloc(sizeof(int *) * (info.ac - 4));
	if (!fd)
		exit(EXIT_FAILURE);
	while (i < info.ac - 4)
	{
		fd[i] = malloc(sizeof(int) * 2);
		if (!fd[i])
			exit(EXIT_FAILURE);
		i++;
	}
	i = 0;
	while (i < info.ac - 4)
	{
		if (pipe(fd[i]) == -1)
			ft_putchar_fd("Pipe error.\n", 2),exit(EXIT_FAILURE);
		i++;
	}
	return (fd);
}
