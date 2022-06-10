/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleblanc <fleblanc@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:43:28 by fleblanc          #+#    #+#             */
/*   Updated: 2022/05/06 16:50:18 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_unsigned_minus(t_printf *tab, unsigned int u, int index)
{
	index = tab->width - ft_intlen(u);
	tab->tot_len += tab->width;
	ft_putnbr_u_fd(u, tab, 1);
	while (index != 0)
	{
		ft_putchar_fd(' ', 1);
		index--;
	}
}

void	ft_printf_unsigned_zero(t_printf *tab, unsigned int u, int index)
{
	index = tab->width - ft_intlen(u);
	tab->tot_len += tab->width;
	while (index != 0)
	{
		ft_putchar_fd('0', 1);
		index--;
	}
	ft_putnbr_u_fd(u, tab, 1);
}

void	ft_printf_unsigned_width(t_printf *tab, unsigned int u, int index)
{
	index = tab->width - ft_intlen(u);
	tab->tot_len += tab->width;
	while (index != 0)
	{
		ft_putchar_fd(' ', 1);
		index--;
	}
	ft_putnbr_u_fd(u, tab, 1);
}

int	ft_printf_unsigned(t_printf *tab, int i)
{
	unsigned int	u;
	int				index;

	index = 0;
	u = va_arg(tab->args, unsigned int);
	if (tab->minus == 1 && tab->width > (int)ft_intlen(u))
		ft_printf_unsigned_minus(tab, u, index);
	else if ((tab->zero == 1 || tab->dot == 1)
		&& tab->width > (int)ft_intlen(u))
		ft_printf_unsigned_zero(tab, u, index);
	else if (tab->width > (int)ft_intlen(u) && tab->count_flags == 0)
		ft_printf_unsigned_width(tab, u, index);
	else
	{
		ft_putnbr_u_fd(u, tab, 1);
		tab->tot_len += ft_intlen(u);
	}
	ft_return_value_u(tab);
	i += 1;
	return (i);
}
