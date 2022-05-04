/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_processing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniilvoronin <daniilvoronin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 22:42:43 by daniilvoron       #+#    #+#             */
/*   Updated: 2022/05/04 22:46:16 by daniilvoron      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex(t_pipex_arg info, int **fd, int *pid)
{
	int	i;

	i = 0;
	while (i < info.ac - 3)
	{
		pid[i] = fork();
		if (pid[i] == 0)
			child_process(info, i, fd);
		else if (pid[i] < 0)
			exit(EXIT_FAILURE);
		i++;
	}
	return (0);
}
