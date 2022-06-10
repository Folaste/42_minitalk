/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleblanc <fleblanc@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:15:23 by fleblanc          #+#    #+#             */
/*   Updated: 2022/06/09 14:33:51 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	main(int argc, char **argv)
{
	(void) argv;
	if (argc != 1)
		ft_printf("Error.\nServer doesn't take any arguments !\n");
	else
	{
		ft_printf("PID = %d\n", getpid());
		signal(SIGUSR1, ft_received_signal);
		signal(SIGUSR2, ft_received_signal);
		while (1)
			continue ;
	}
	return (0);
}

void	ft_received_signal(int signal)
{
	static int	i = 0;
	char		tab[8];
	static char	result[524288];
	char		c;
	int			j;

	j = 0;
	if (signal == SIGUSR1)
		tab[i] = '0';
	else if (signal == SIGUSR2)
		tab[i] = '1';
	i++;
	if (i >= 8)
	{
		c = ft_btoc(tab);
		result[j] = c;
		j++;
		i = 0;
	}
	if (result[j] == 0)
		ft_printf("%s", result);
}
