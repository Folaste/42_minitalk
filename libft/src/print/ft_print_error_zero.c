/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error_zero.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleblanc <fleblanc@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:33:47 by fleblanc          #+#    #+#             */
/*   Updated: 2022/06/16 18:25:35 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_print_error_zero(char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	return (0);
}
