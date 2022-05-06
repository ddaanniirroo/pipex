/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniilvoronin <daniilvoronin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 18:13:42 by daniilvoron       #+#    #+#             */
/*   Updated: 2022/05/06 13:43:53 by daniilvoron      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_countwords(const char *s, char c)
{
	int	count;
	int	words;

	count = 0;
	words = 0;
	while (s[count] == c && c)
		count++;
	while (s[count])
	{
		while (s[count] && s[count] != c)
			count++;
		words++;
		while (s[count] == c && c)
			count++;
	}
	return (words);
}

static char	**freesplit(int temp, char **strs)
{
	while (temp >= 0)
	{
		free(strs[temp]);
		temp--;
	}
	free(strs);
	return (strs);
}

char	**fillarr(const char *s, char **strs, char c)
{
	int	count;
	int	temp;
	int	start;

	count = 0;
	temp = 0;
	while (s[count] == c && c)
		count++;
	while (s[count])
	{
		start = count;
		while (s[count] && s[count] != c)
			count++;
		strs[temp] = ft_substr(s, start, count - start);
		if (!strs[temp])
		{
			freesplit(temp, strs);
			return (NULL);
		}
		temp++;
		while (s[count] == c && c)
			count++;
	}
	strs[temp] = NULL;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	//int		temp;

	if (!s)
		exit(EXIT_FAILURE);
	//temp = 0;
	strs = malloc((ft_countwords(s, c) + 1) * sizeof(char *));
	if (!strs)
		exit(EXIT_FAILURE);
	if (!fillarr(s, strs, c))
		exit(EXIT_FAILURE);
	return (strs);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	count;

	if (!dst || !src)
		return (0);
	count = 0;
	if (dstsize)
	{
		while (src[count] && dstsize - 1)
		{
			dst[count] = src[count];
			count++;
			dstsize--;
		}
		dst[count] = 0;
	}
	while (src[count])
		count++;
	return (count);
}
