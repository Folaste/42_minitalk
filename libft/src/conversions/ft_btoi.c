/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleblanc <fleblanc@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:51:19 by fleblanc          #+#    #+#             */
/*   Updated: 2022/06/09 15:41:26 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

unsigned int	ft_btoi(char *tab)
{
	int				i;
	int				power;
	unsigned int	result;

	i = 31;
	power = 1;
	result = 0;
	while (i != -1)
	{
		if (tab[i] == '1')
			result += ((tab[i] - '0') * power);
		power *= 2;
		i--;
	}
	return (result);
}
