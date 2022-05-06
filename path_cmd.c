/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniilvoronin <daniilvoronin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:48:51 by daniilvoron       #+#    #+#             */
/*   Updated: 2022/05/06 15:43:15 by daniilvoron      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_path(char **path)
{
	int	i;

	i = 0;
	while (path[i] != NULL)
	{
		free(path[i]);
		i++;
	}
	free(path);
	path = NULL;
}

char	**find_path(char **envp)
{
	char	**envpath = NULL;
	int		i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (!(ft_strncmp("PATH=", envp[i], 5)))
		{
			envpath = ft_split(envp[i] + 5, ':');
			break ;
		}
		i++;
	}
	return (envpath);
}
