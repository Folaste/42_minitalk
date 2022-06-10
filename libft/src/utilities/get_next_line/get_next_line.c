/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleblanc <fleblanc@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:36:46 by fleblanc          #+#    #+#             */
/*   Updated: 2022/05/06 16:46:37 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_new_buffer(char *old_buffer)
{
	char	*new_buffer;
	long	len;
	long	i;

	i = 0;
	if (ft_strlen_gnl(old_buffer) == 0)
	{
		free(old_buffer);
		return (NULL);
	}
	while (old_buffer[i] != '\n' && old_buffer[i] != '\0')
		i++;
	if (old_buffer[i] == '\n')
	{
		len = ft_strlen_gnl(old_buffer + i + 1);
		new_buffer = ft_substr_gnl(old_buffer, (i + 1), len);
	}
	else
	{
		new_buffer = ft_substr_gnl(old_buffer, i, 1);
	}
	free(old_buffer);
	return (new_buffer);
}

int	ft_find_eol(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (ft_strlen_gnl(str));
}

char	*get_next_line(int fd)
{
	static char	*buffer[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 4096)
		return (NULL);
	if (!buffer[fd])
	{
		buffer[fd] = malloc(sizeof(char));
		buffer[fd][0] = 0;
	}
	buffer[fd] = ft_read(fd, buffer[fd]);
	if (buffer[fd] == NULL)
		return (NULL);
	line = ft_recover_line(buffer[fd]);
	buffer[fd] = ft_new_buffer(buffer[fd]);
	if (line[0] == 0)
	{	
		free(line);
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	return (line);
}

char	*ft_recover_line(char *buffer)
{
	int		index_eol;
	char	*line;

	index_eol = ft_find_eol(buffer);
	line = ft_substr_gnl(buffer, 0, index_eol + 1);
	return (line);
}

char	*ft_read(int fd, char *buffer)
{
	char	*tmp_buff;
	int		return_read;

	return_read = 1;
	tmp_buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp_buff)
		return (NULL);
	tmp_buff[0] = 0;
	while (ft_strchr_gnl(tmp_buff, '\n') == NULL && return_read != 0)
	{
		return_read = read(fd, tmp_buff, BUFFER_SIZE);
		if (return_read == -1)
		{
			free(buffer);
			free(tmp_buff);
			return (NULL);
		}
		tmp_buff[return_read] = 0;
		buffer = ft_strjoin_gnl(buffer, tmp_buff);
	}
	free(tmp_buff);
	return (buffer);
}
