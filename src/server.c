/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleblanc <fleblanc@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:15:23 by fleblanc          #+#    #+#             */
/*   Updated: 2022/07/06 16:50:37 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

int	main(int argc, char **argv)
{
	(void) argv;
	if (argc != 1)
		ft_printf("Error.\nServer doesn't take any arguments !\n");
	else
	{
		ft_printf("PID = %d\n", getpid());
		signal(SIGUSR1, ft_received_message);
		signal(SIGUSR2, ft_received_message);
		while (1)
			continue ;
	}
	return (0);
}

void	ft_received_message(int signal)
{
	static int	i = 0;
	static int	length = -1;

	if (i <= 32)
	{
		length = ft_get_length(signal);
		i++;
	}
	else
	{
		ft_get_message(signal, length);
		if (i == (32 + (length * 8)))
		{
			i = 0;
			length = -1;
		}
		else
			i++;
	}
}

int	ft_get_length(int signal)
{
	static int	i = 0;
	static char	b_length[32];
	static int	length = -1;

	if (i < 32)
	{
		if (signal == SIGUSR1)
			b_length[i] = '0';
		else if (signal == SIGUSR2)
			b_length[i] = '1';
		i++;
	}
	else
	{
		length = ft_btoi(b_length);
		i = 0;
		return (length);
	}
	return (-1);
}

void	ft_get_message(int signal, int length)
{
	static int	i = 0;
	static char	b_ch[9] = " ";
	static int	j = 0;
	static char	*result;

	if (result == NULL)
		result = ft_calloc((length + 1), sizeof(char));
	if (signal == SIGUSR1)
		b_ch[i++] = '0';
	else if (signal == SIGUSR2)
		b_ch[i++] = '1';
	if (i == 8)
	{
		result[j++] = ft_btoc(b_ch);
		i = 0;
	}
	if (j == length)
	{
		result[j] = 0;
		ft_printf("%s", result);
		j = 0;
		free(result);
		result = NULL;
	}
}
