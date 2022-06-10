/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleblanc <fleblanc@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:19:49 by fleblanc          #+#    #+#             */
/*   Updated: 2022/06/09 14:41:05 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		ft_printf("Invalid arguments.\nFormat is : ./client [PID] [Message]\n");
	else
	{
		if (ft_check_error(argv) == 0 || ft_atoi(argv[1]) < 1)
		{
			ft_printf("Error\nPID is wrong.\n");
			return (0);
		}
		pid = ft_atoi(argv[1]);
		ft_send_message(pid, argv[2]);
		ft_send_message(pid, "\0");
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	ft_check_error(char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i])
	{
		if (ft_isdigit(argv[1][i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_send_message(int pid, char *message)
{
	char	*tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (message[i])
	{
		tab = ft_ctob(message[i]);
		while (tab[j])
		{
			if (tab[j] == '1')
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			j++;
			usleep(100);
		}
		free(tab);
		j = 0;
		i++;
	}
}
