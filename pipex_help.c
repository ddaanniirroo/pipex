/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniilvoronin <daniilvoronin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:25:24 by cprester          #+#    #+#             */
/*   Updated: 2022/05/04 17:37:52 by daniilvoron      ###   ########.fr       */
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

}
