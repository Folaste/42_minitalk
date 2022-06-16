/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleblanc <fleblanc@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:59:44 by fleblanc          #+#    #+#             */
/*   Updated: 2022/05/06 16:50:01 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/libft.h"

void	ft_return_value_p(t_printf *tab)
{
	tab->tot_len -= 2;
	if (tab->minus == 1)
		tab->tot_len -= 1;
	if (tab->width != 0 || tab->zero == 1)
		tab->tot_len -= ft_intlen(tab->width);
}

void	ft_putptr_fd(unsigned long p, t_printf *tab, int fd, char *base)
{
	char			c;
	unsigned long	p_copy;

	p_copy = p;
	if (p_copy >= 16)
		ft_putptr_fd(p_copy / 16, tab, fd, base);
	c = base[p % 16];
	ft_putchar_fd(c, fd);
	tab->tot_len += 1;
}

int	ft_hexalen(unsigned long p)
{
	int	res;

	res = 0;
	if (p == 0)
		return (1);
	while (p > 0)
	{
		res++;
		p /= 16;
	}
	return (res);
}
