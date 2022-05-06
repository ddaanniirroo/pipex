/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniilvoronin <daniilvoronin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 22:26:43 by daniilvoron       #+#    #+#             */
/*   Updated: 2022/05/06 13:42:48 by daniilvoron      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	if (!s)
		return (0);
	count = 0;
	while (s[count])
		count++;
	return (count);
}


int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s1dup;
	unsigned char	*s2dup;
	size_t			count;

	if (n == 0)
		return (0);
	s1dup = (unsigned char *)s1;
	s2dup = (unsigned char *)s2;
	count = 0;
	while (s1dup[count] && count < n - 1 && s1dup[count] == s2dup[count])
		count++;
	return (s1dup[count] - s2dup[count]);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		length;

	if (!s1)
		return (NULL);
	length = ft_strlen(s1);
	s2 = malloc((length + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	s2[length] = 0;
	while (length > 0)
	{
		length--;
		s2[length] = s1[length];
	}
	return (s2);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	size_t	new_len;
	char	*str;

	if (!s)
		return (NULL);
	s1 = (char *)s;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	new_len = ft_strlen(s + start);
	if (new_len < len)
		len = new_len;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + start, len + 1);
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		nb;
	char	*str;

	i = 0;
	j = 0;
	nb = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * \
	(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
		str[nb++] = s1[i++];
	while (s2[j])
		str[nb++] = s2[j++];
	str[nb] = '\0';
	return (str);
}
