/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleblanc <fleblanc@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 12:05:53 by fleblanc          #+#    #+#             */
/*   Updated: 2022/05/06 16:49:21 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_number(t_printf *tab, int i)
{
	int	index;
	int	nbr;
	int	size;

	index = 0;
	nbr = va_arg(tab->args, int);
	size = ft_intlen(nbr);
	ft_choice_write(tab, nbr, size, index);
	ft_return_value_nbr(tab);
	i++;
	return (i);
}

void	ft_choice_write(t_printf *tab, int nbr, int size, int index)
{
	if (tab->minus == 1 && tab->width > size)
		ft_printf_number_minus(tab, nbr, index, size);
	else if (tab->width > size && tab->zero == 1)
		ft_printf_number_zero(tab, nbr, index, size);
	else if (tab->width >= size && tab->dot == 1)
		ft_printf_number_dot(tab, nbr, index, size);
	else if (tab->plus == 1 && nbr >= 0)
	{
		tab->tot_len += write(1, "+", 1);
		ft_putnbr_fd(nbr, 1);
		tab->tot_len += size;
	}
	else if (tab->space == 1 && nbr >= 0)
	{
		tab->tot_len += write(1, " ", 1);
		ft_putnbr_fd(nbr, 1);
		tab->tot_len += size;
	}
	else if (tab->count_flags == 0 && tab->width > (int)ft_intlen(nbr))
		ft_printf_number_width(tab, nbr, index, size);
	else
	{
		ft_putnbr_fd(nbr, 1);
		tab->tot_len += size;
	}
}

void	ft_printf_number_minus(t_printf *tab, int nbr, int index, int size)
{
	index = tab->width - size;
	tab->tot_len += tab->width;
	ft_putnbr_fd(nbr, 1);
	while (index != 0)
	{
		ft_putchar_fd(' ', 1);
		index--;
	}
}

void	ft_printf_number_zero(t_printf *tab, int nbr, int index, int size)
{
	if (nbr < 0 && tab->zero == 1)
	{
		write(1, "-", 1);
		nbr *= -1;
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

void	ft_printf_number_width(t_printf *tab, int nbr, int index, int size)
{
	index = tab->width - size;
	tab->tot_len += tab->width;
	while (index != 0)
	{
		ft_putchar_fd(' ', 1);
		index--;
	}
	ft_putnbr_fd(nbr, 1);
}
