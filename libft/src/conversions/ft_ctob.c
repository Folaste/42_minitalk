/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleblanc <fleblanc@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:43:48 by fleblanc          #+#    #+#             */
/*   Updated: 2022/06/09 12:05:09 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_ctob(int c)
{
	char			*tab;
	int				i;
	unsigned int	power;

	tab = ft_calloc(9, sizeof(char));
	if (!tab)
		return (NULL);
	i = 0;
	power = 128;
	while (i < 8)
	{
		if (c / power == 0)
			tab[i] = '0';
		else
		{
			tab[i] = '1';
			c -= power;
		}
		power /= 2;
		i++;
	}
	return (tab);
}
