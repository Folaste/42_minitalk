/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 10:33:12 by fleblanc          #+#    #+#             */
/*   Updated: 2022/04/12 16:41:16 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*cdest;
	const char	*csrc;

	cdest = dest;
	csrc = src;
	if (!dest && !src)
		return (NULL);
	while (n--)
	{
		if (src < dest)
			cdest[n] = csrc[n];
		else
			*cdest++ = *csrc++;
	}
	return (dest);
}
