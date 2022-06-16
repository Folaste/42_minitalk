/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleblanc <fleblanc@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 16:32:08 by fleblanc          #+#    #+#             */
/*   Updated: 2022/05/06 16:48:23 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/libft.h"

void	ft_return_value_x(t_printf *tab)
{
	tab->tot_len -= 2;
	if (tab->count_flags == 1)
		tab->tot_len -= 1;
	if (tab->width != 0)
		tab->tot_len -= ft_intlen(tab->width);
}

int	ft_printf_hexa(t_printf *tab, int i, char x_case)
{
	unsigned int	x;
	char			*base;
	int				index;

	if (x_case == 'x')
		base = HEX_BASE_MIN;
	else
		base = HEX_BASE_MAJ;
	index = 0;
	x = va_arg(tab->args, unsigned int);
	if (tab->minus == 1 && tab->width > ft_hexalen(x))
		ft_printf_hexa_minus(tab, x, base, index);
	else if ((tab->zero == 1 || tab->dot == 1) && tab->width > ft_hexalen(x))
		ft_printf_hexa_zero(tab, x, base, index);
	else if (tab->hash == 1)
		ft_printf_hexa_hash(tab, x, base);
	else if (tab->width > ft_hexalen(x) && tab->count_flags == 0)
		ft_printf_hexa_width(tab, x, base, index);
	else
		ft_putptr_fd(x, tab, 1, base);
	ft_return_value_x(tab);
	i++;
	return (i);
}
