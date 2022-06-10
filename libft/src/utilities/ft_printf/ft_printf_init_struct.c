/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_init_struct.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleblanc <fleblanc@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 14:44:56 by fleblanc          #+#    #+#             */
/*   Updated: 2022/05/06 16:48:58 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_init_tab(t_printf *tab)
{
	tab->dot = 0;
	tab->zero = 0;
	tab->minus = 0;
	tab->space = 0;
	tab->plus = 0;
	tab->hash = 0;
	tab->tot_len = 0;
	tab->width = 0;
	tab->count_flags = 0;
}

void	ft_reset_tab(t_printf *tab)
{
	tab->dot = 0;
	tab->zero = 0;
	tab->minus = 0;
	tab->space = 0;
	tab->plus = 0;
	tab->hash = 0;
	tab->width = 0;
	tab->count_flags = 0;
}

void	ft_count_flags(t_printf *tab)
{
	if (tab->dot == 1)
		tab->count_flags += 1;
	if (tab->zero == 1)
		tab->count_flags += 1;
	if (tab->minus == 1)
		tab->count_flags += 1;
	if (tab->space == 1)
		tab->count_flags += 1;
	if (tab->plus == 1)
		tab->count_flags += 1;
	if (tab->hash == 1)
		tab->count_flags += 1;
}
