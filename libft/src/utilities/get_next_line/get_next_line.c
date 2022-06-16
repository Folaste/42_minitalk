/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleblanc <fleblanc@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:36:46 by fleblanc          #+#    #+#             */
/*   Updated: 2022/06/14 12:08:39 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/libft.h"

char	*get_next_line(int fd)
{
	int		i;
	int		rd;
	char	character;
	char	*buffer;

	i = 0;
	rd = 1;
	buffer = (char *)malloc(10000);
	while (rd > 0)
	{
		rd = read(fd, &character, 1);
		buffer[i++] = character;
		if (character == '\n')
			break ;
	}
	if ((!buffer[i - 1] && !rd) || rd == -1)
	{
		free(buffer);
		return (NULL);
	}
	buffer[i] = '\0';
	return (buffer);
}
