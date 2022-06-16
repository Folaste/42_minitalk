/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleblanc <fleblanc@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 15:02:01 by fleblanc          #+#    #+#             */
/*   Updated: 2022/05/06 16:49:40 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/libft.h"

void	ft_printf_pointer_minus(t_printf *tab, unsigned long p, int index)
{
	index = tab->width - (ft_hexalen(p) + 2);
	tab->tot_len += write(1, "0x", 2);
	ft_putptr_fd(p, tab, 1, HEX_BASE_MIN);
	while (index != 0)
	{
		ft_putchar_fd(' ', 1);
		index--;
		tab->tot_len += 1;
	}
}

void	ft_printf_pointer_width(t_printf *tab, unsigned long p, int index)
{
	index = tab->width - (ft_hexalen(p) + 2);
	while (index != 0)
	{
		ft_putchar_fd(' ', 1);
		index--;
		tab->tot_len += 1;
	}
	tab->tot_len += write(1, "0x", 2);
	ft_putptr_fd(p, tab, 1, HEX_BASE_MIN);
}

int	ft_printf_pointer(t_printf *tab, int i)
{
	unsigned long	p;
	int				index;

	index = 0;
	p = (unsigned long)va_arg(tab->args, void *);
	if (!p)
		tab->tot_len += write(1, "(nil)", 5);
	else if (tab->minus == 1 && tab->width > ft_hexalen(p) + 2)
		ft_printf_pointer_minus(tab, p, index);
	else if ((tab->width > ft_hexalen(p) + 2)
		&& (tab->count_flags == 0 || tab->zero == 1))
		ft_printf_pointer_width(tab, p, index);
	else
	{
		tab->tot_len += write(1, "0x", 2);
		ft_putptr_fd(p, tab, 1, HEX_BASE_MIN);
	}
	ft_return_value_p(tab);
	i++;
	return (i);
}
