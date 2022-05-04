/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprester <cprester@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:55:05 by cprester          #+#    #+#             */
/*   Updated: 2022/05/04 18:14:09 by cprester         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include <errno.h>

typedef struct s_pipex
{
	pid_t	pid;
	int		in;
	int		out;
	int		end;
}	t_pipex;

//ft_split
char	**ft_split(char *s, char c);

//utils
int		ft_strlen(char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_strjoin(char *s1, char *s2);

//pipex
int		open_files(char *file, int flag);
int		child_proc(int in, int *end, char **argv, char **envp);
int		parents_proc(int out, int *end, char **argv, char **envp);
void	pipex_f(t_pipex *pipex, char **argv, char **envp);

//pipex_help
char	*data_processing(char **argv, char **envp, int argv_numb);
void	right_path(char **my_path, char **cmd, char **envp);
void	err_putstr(char *str);
char	*search_path(char **envp);

#endif