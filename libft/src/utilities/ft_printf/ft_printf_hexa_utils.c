/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleblanc <fleblanc@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 18:45:05 by fleblanc          #+#    #+#             */
/*   Updated: 2022/05/06 16:48:33 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/libft.h"

void	ft_printf_hexa_minus(t_printf *tab, unsigned int x,
								char *base, int index)
{
	index = tab->width - ft_hexalen(x);
	ft_putptr_fd(x, tab, 1, base);
	while (index != 0)
	{
		ft_putchar_fd(' ', 1);
		index--;
		tab->tot_len += 1;
	}
}

void	ft_printf_hexa_zero(t_printf *tab, unsigned int x,
								char *base, int index)
{
	index = tab->width - ft_hexalen(x);
	while (index != 0)
	{
		tab->tot_len += write(1, "0", 1);
		index--;
	}
	ft_putptr_fd(x, tab, 1, base);
}

void	ft_printf_hexa_hash(t_printf *tab, unsigned int x, char *base)
{
	if (x != 0)
	{
		if (base[10] == 'a')
			tab->tot_len += write(1, "0x", 2);
		else
			tab->tot_len += write(1, "0X", 2);
	}
	ft_putptr_fd(x, tab, 1, base);
}

void	ft_printf_hexa_width(t_printf *tab, unsigned int x,
								char *base, int index)
{
	index = tab->width - ft_hexalen(x);
	while (index != 0)
	{
		ft_putchar_fd(' ', 1);
		index--;
		tab->tot_len += 1;
	}
	ft_putptr_fd(x, tab, 1, base);
}
