/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleblanc <fleblanc@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:17:40 by fleblanc          #+#    #+#             */
/*   Updated: 2022/07/03 18:22:11 by fleblanc_        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/inc/libft.h"
# include <signal.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>

/*--- client.c ---*/
int		ft_check_error(char **argv);
void	ft_send_length(int pid, int length);
void	ft_send_message(int pid, char *message);

/*--- server.c ---*/
void	ft_received_message(int signal);
int		ft_get_length(int signal);
char	*ft_get_message(int signal, int length, char *result);

#endif
