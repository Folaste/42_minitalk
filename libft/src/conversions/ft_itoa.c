/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:40:40 by fleblanc          #+#    #+#             */
/*   Updated: 2022/04/18 11:32:21 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	size_t		len;
	char		*array;
	long int	copy_n;

	copy_n = n;
	len = ft_intlen(n) + 1;
	array = ft_calloc(len, sizeof(char));
	if (array == NULL)
		return (NULL);
	len -= 2;
	if (copy_n < 0)
	{
		array[0] = '-';
		copy_n *= -1;
	}
	while (copy_n > 9)
	{
		array[len] = (copy_n % 10) + '0';
		copy_n /= 10;
		len--;
	}
	array[len] = copy_n + '0';
	return (array);
}
