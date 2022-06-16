/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleblanc <fleblanc@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:43:48 by fleblanc          #+#    #+#             */
/*   Updated: 2022/05/06 16:50:25 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/libft.h"

void	ft_return_value_u(t_printf *tab)
{
	tab->tot_len -= 2;
	if (tab->count_flags == 1)
		tab->tot_len -= 1;
	if (tab->width != 0)
		tab->tot_len -= ft_intlen(tab->width);
}

void	ft_putnbr_u_fd(unsigned int u, t_printf *tab, int fd)
{
	if (u >= 10)
	{
		ft_putnbr_u_fd(u / 10, tab, fd);
		ft_putchar_fd((u % 10) + '0', 1);
	}
	else
		ft_putchar_fd(u + '0', 1);
}
