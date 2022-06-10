/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleblanc <fleblanc@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:17:40 by fleblanc          #+#    #+#             */
/*   Updated: 2022/06/09 15:42:06 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/includes/libft.h"
# include <signal.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>

/*--- client.c ---*/
int		ft_check_error(char **argv);
void	ft_send_message(int pid, char *message);

/*--- server.c ---*/
void	ft_received_signal(int signal);

#endif
