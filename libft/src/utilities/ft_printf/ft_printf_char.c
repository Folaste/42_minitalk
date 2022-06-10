/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleblanc <fleblanc@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:25:35 by fleblanc          #+#    #+#             */
/*   Updated: 2022/05/06 16:47:44 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_char(t_printf *tab, int i)
{
	int	c;
	int	index;

	c = va_arg(tab->args, int);
	if (tab->minus == 0)
	{
		ft_putchar_fd(c, 1);
		tab->tot_len -= 1;
	}
	else
	{
		tab->tot_len += tab->width - 3 - ft_intlen(tab->width);
		index = tab->width - 1;
		ft_putchar_fd(c, 1);
		while (index != 0)
		{
			ft_putchar_fd(' ', 1);
			index--;
		}
	}
	i++;
	return (i);
}
