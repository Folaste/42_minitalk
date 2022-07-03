/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleblanc <fleblanc@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:15:23 by fleblanc          #+#    #+#             */
/*   Updated: 2022/07/03 18:25:28 by fleblanc_        ###   ########.fr       */
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
	char	*result;
	int		length;

	if (signal == SIGUSR1 || signal == SIGUSR2)
	{
		length = ft_get_length(signal);
		if (length != -1)
		{
			result = ft_calloc(length + 1, sizeof(char));
			if (!result)
				return ;
			result = ft_get_message(signal, length, result);
			if (result != NULL)
				ft_printf("%s", result);
			free(result);
		}
	}
}

int	ft_get_length(int signal)
{
	static int	i = 0;
	char		tab[33];
	int			length;

	tab[32] = 0;
	if (signal == SIGUSR1)
		tab[i] = '0';
	else if (signal == SIGUSR2)
		tab[i] = '1';
	i++;
	if (i >= 32)
	{
		length = ft_btoi(tab);
		return (length);
	}
	return (-1);
}

char	*ft_get_message(int signal, int length, char *result)
{
	static int	i = 0;
	char		b_ch[8];
	char		ch;
	static int	j = 0;

	while (j != length)
	{
		if (signal == SIGUSR1)
			b_ch[i] = '0';
		else if (signal == SIGUSR2)
			b_ch[i] = '1';
		i++;
		if (i == 8)
		{
			ch = ft_btoc(b_ch);
			result[j] = ch;
			j++;
			i = 0;
		}
	}
	if (j == length)
		return (result);
	return (NULL);
}
/*
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
	if (result[j] == '\0')
		ft_printf("%s", result);
}*/
