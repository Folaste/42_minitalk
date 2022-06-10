/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:32:49 by fleblanc          #+#    #+#             */
/*   Updated: 2022/04/06 17:11:07 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*s_copy;
	unsigned char	c_copy;

	c_copy = (unsigned char)c;
	s_copy = (unsigned char *)s;
	while (*s_copy != c_copy)
	{
		if (*s_copy++ == 0)
			return (NULL);
	}
	return ((char *)s_copy);
}
