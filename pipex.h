/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniilvoronin <daniilvoronin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:14:00 by cprester          #+#    #+#             */
/*   Updated: 2022/05/06 13:49:32 by daniilvoron      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
#include <string.h>

typedef struct s_pipex_arg
{
	char	**envp;
	char	**av;
	int		ac;
}	t_pipex_arg;

typedef struct s_info
{
	int	start;
	int	end;
	int	temp;
	int	quote;
}	t_info;


//ft_split.c
char	**fillarr(const char *s, char **strs, char c);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

// //libft_f.c
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

char	**find_path(char **envp);
void	free_path(char **path);

#endif
