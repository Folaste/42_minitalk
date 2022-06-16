/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_check_args.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleblanc <fleblanc@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:54:33 by fleblanc          #+#    #+#             */
/*   Updated: 2022/05/06 16:48:06 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/libft.h"

int	ft_check_flags(t_printf *tab, const char *format, int i)
{	
	i++;
	while (format[i] && !ft_strchr(CASTS, format[i]))
	{
		if (format[i] == '-')
			tab->minus = 1;
		else if (format[i] == '0')
			tab->zero = 1;
		else if (format[i] == '.')
			tab->dot = 1;
		else if (format[i] == '+')
			tab->plus = 1;
		else if (format[i] == ' ')
			tab->space = 1;
		else if (format[i] == '#')
			tab->hash = 1;
		else if (ft_isdigit(format[i]) != 0)
		{	
			tab->width = ft_atoi(format + i);
			i += ft_intlen(tab->width) - 1;
		}
		i++;
	}
	ft_count_flags(tab);
	i = ft_check_cast(tab, format, i);
	return (i);
}

int	ft_check_cast(t_printf *tab, const char *format, int i)
{
	if (format[i] == 'c')
		i = ft_printf_char(tab, i);
	else if (format[i] == 's')
		i = ft_printf_string(tab, i);
	else if (format[i] == 'p')
		i = ft_printf_pointer(tab, i);
	else if (format[i] == 'x' || format[i] == 'X')
		i = ft_printf_hexa(tab, i, format[i]);
	else if (format[i] == 'u')
		i = ft_printf_unsigned(tab, i);
	else if (format[i] == 'd' || format[i] == 'i')
		i = ft_printf_number(tab, i);
	else if (format[i] == '%')
	{
		ft_putchar_fd('%', 1);
		tab->tot_len -= 1;
		i++;
	}
	return (i);
}
