/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleblanc <fleblanc@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:11:04 by fleblanc          #+#    #+#             */
/*   Updated: 2022/04/22 11:55:44 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static int	ft_err_base(char *base)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	if (ft_strlen(base) == 0 || ft_strlen(base) == 1)
		return (0);
	while (base[i++])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
	}
	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base_fd(int nbr, char *base, int fd)
{
	int	len;

	if (ft_err_base(base) == 0)
		return ;
	len = (int)ft_strlen(base);
	if (nbr >= 0 && nbr < len)
		ft_putchar_fd(base[nbr], 1);
	else
	{
		ft_putnbr_base_fd(nbr / len, base, fd);
		ft_putnbr_base_fd(nbr % len, base, fd);
	}
}
