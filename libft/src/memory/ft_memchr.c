/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:51:10 by fleblanc          #+#    #+#             */
/*   Updated: 2022/04/06 17:01:11 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_copy;
	unsigned char	c_copy;

	s_copy = (unsigned char *)s;
	c_copy = (unsigned char)c;
	while (n != 0)
	{
		if (*s_copy == c_copy)
			return ((unsigned char *)s_copy);
		s_copy++;
		n--;
	}
	return (NULL);
}
