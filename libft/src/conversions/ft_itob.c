/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleblanc <fleblanc@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:18:28 by fleblanc          #+#    #+#             */
/*   Updated: 2022/06/08 17:50:38 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_itob(unsigned int nb)
{
	char			*tab;
	int				i;
	unsigned int	power;

	tab = ft_calloc(33, sizeof(char));
	if (!tab)
		return (NULL);
	i = 0;
	power = 2147483648;
	while (i < 32)
	{
		if (nb / power == 0)
			tab[i] = '0';
		else
		{
			tab[i] = '1';
			nb -= power;
		}
		power /= 2;
		i++;
	}
	tab[i] = 0;
	return (tab);
}
