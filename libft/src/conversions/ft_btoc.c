/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleblanc <fleblanc@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:46:25 by fleblanc          #+#    #+#             */
/*   Updated: 2022/06/08 18:47:42 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_btoc(char *tab)
{
	int				i;
	int				power;
	unsigned int	result;

	i = 7;
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
