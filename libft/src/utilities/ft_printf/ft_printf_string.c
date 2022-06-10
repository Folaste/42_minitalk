/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleblanc <fleblanc@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:02:18 by fleblanc          #+#    #+#             */
/*   Updated: 2022/06/09 14:57:14 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_return_value_s(t_printf *tab)
{
	tab->tot_len -= 2;
	if (tab->dot == 1 || tab->zero == 1 || tab->minus == 1 || tab->space == 1)
		tab->tot_len -= 1;
	if (tab->width != 0 || tab->zero == 1)
		tab->tot_len -= ft_intlen(tab->width);
}

void	ft_printf_string_dot(t_printf *tab, char *str, int index)
{
	int	width;

	width = tab->width;
	tab->tot_len += tab->width;
	while (width != 0)
	{
		ft_putchar_fd(str[index], 1);
		index++;
		width--;
	}
}

void	ft_printf_string_width(t_printf *tab, char *str, int index)
{
	index = tab->width - (int)ft_strlen(str);
	tab->tot_len += tab->width;
	while (index != 0)
	{
		ft_putchar_fd(' ', 1);
		index--;
	}
	ft_putstr_fd(str, 1);
}

void	ft_printf_string_minus(t_printf *tab, char *str, int index)
{
	index = tab->width - (int)ft_strlen(str);
	tab->tot_len += tab->width;
	ft_putstr_fd(str, 1);
	while (index != 0)
	{
		ft_putchar_fd(' ', 1);
		index--;
	}
}

int	ft_printf_string(t_printf *tab, int i)
{
	char	*str;
	int		index;

	index = 0;
	str = va_arg(tab->args, char *);
	if (!str)
		tab->tot_len += write(1, "(null)", 6);
	else if (tab->dot == 1 && tab->width < (int)ft_strlen(str))
		ft_printf_string_dot(tab, str, index);
	else if (tab->minus == 1 && tab->width > (int)ft_strlen(str))
		ft_printf_string_minus(tab, str, index);
	else if ((tab->space == 1 || tab->count_flags == 0)
		&& tab->width > (int)ft_strlen(str))
		ft_printf_string_width(tab, str, index);
	else
	{
		ft_putstr_fd(str, 1);
		tab->tot_len += ft_strlen(str);
	}
	ft_return_value_s(tab);
	i++;
	return (i);
}
