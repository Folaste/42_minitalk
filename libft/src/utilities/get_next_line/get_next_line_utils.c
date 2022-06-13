/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleblanc <fleblanc@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:37:39 by fleblanc          #+#    #+#             */
/*   Updated: 2022/05/06 16:46:49 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strjoin_gnl(const char *s1, const char *s2)
{
	char	*array;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	array = malloc((ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1) * sizeof(char));
	if (array == NULL)
		return (NULL);
	while (s1[i])
	{
		array[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		array[i + j] = s2[j];
		j++;
	}
	array[i + j] = 0;
	free((char *)s1);
	return (array);
}

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	unsigned char	*s_copy;
	unsigned char	c_copy;

	c_copy = (unsigned char)c;
	s_copy = (unsigned char *)s;
	if (s == NULL)
		return (NULL);
	while (*s_copy != c_copy)
	{
		if (*s_copy++ == 0)
			return (NULL);
	}
	return ((char *)s_copy);
}

char	*ft_substr_gnl(const char *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start < ft_strlen_gnl(s))
		i = ft_strlen_gnl(s) - start;
	if (i > len)
		i = len;
	if (start > ft_strlen_gnl(s))
	{
		result = malloc(1 * sizeof(char));
		if (result)
			return (result);
		else
			return (NULL);
	}
	result = malloc((i + 1) * sizeof(char));
	if (result)
		ft_strlcpy_gnl(result, (s + start), i + 1);
	else
		return (NULL);
	return (result);
}

size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
	{
		return (ft_strlen_gnl(src));
	}
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (ft_strlen_gnl(src));
}
