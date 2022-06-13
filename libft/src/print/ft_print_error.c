/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleblanc <fleblanc@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:33:47 by fleblanc          #+#    #+#             */
/*   Updated: 2022/06/10 16:46:20 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_print_error(char *msg)
{
	write(2, "Error.\n", 7);
	write(2, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}
