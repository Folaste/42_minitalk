/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleblanc <fleblanc@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 12:06:18 by fleblanc          #+#    #+#             */
/*   Updated: 2022/05/06 16:49:30 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_return_value_nbr(t_printf *tab)
{
	tab->tot_len -= 2;
	if (tab->count_flags == 1)
		tab->tot_len -= 1;
	if (tab->width != 0)
		tab->tot_len -= ft_intlen(tab->width);
}

void	ft_printf_number_dot(t_printf *tab, int nbr, int index, int size)
{
	if (nbr < 0)
	{
		size -= write(1, "-", 1);
		nbr *= -1;
		tab->tot_len += 1;
	}
	index = tab->width - size;
	tab->tot_len += tab->width;
	while (index != 0)
	{
		ft_putchar_fd('0', 1);
		index--;
	}
	ft_putnbr_fd(nbr, 1);
}
