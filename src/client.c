/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleblanc <fleblanc@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:19:49 by fleblanc          #+#    #+#             */
/*   Updated: 2022/07/06 16:50:34 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

int	main(int argc, char **argv)
{
	int	pid;
	int	k_ret;

	if (argc != 3)
		return (ft_print_error_zero("Invalid arguments.\n"));
	else
	{
		if (ft_check_error(argv) == 0 || ft_atoi(argv[1]) < 1)
			return (ft_print_error_zero("PID is not a number.\n"));
		pid = ft_atoi(argv[1]);
		if (argv[2][0] != '\0')
		{
			ft_send_length(pid, (int)ft_strlen(argv[2]));
			k_ret = kill(pid, SIGUSR1);
			if (k_ret == -1)
				ft_print_error_exit("PID is wrong.\n");
			usleep(1);
			ft_send_message(pid, argv[2]);
			exit(EXIT_SUCCESS);
		}
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

void	ft_send_length(int pid, int length)
{
	char	*b_length;
	int		i;

	i = 0;
	b_length = ft_itob(length);
	while (b_length[i])
	{
		if (b_length[i] == '1')
			kill(pid, SIGUSR2);
		else if (b_length[i] == '0')
			kill(pid, SIGUSR1);
		i++;
		usleep(1);
	}
	free(b_length);
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
			usleep(1);
		}
		free(tab);
		j = 0;
		i++;
	}
}
