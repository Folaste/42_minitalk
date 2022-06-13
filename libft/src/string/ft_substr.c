/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 19:29:27 by fleblanc          #+#    #+#             */
/*   Updated: 2022/04/13 16:44:53 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start < ft_strlen(s))
		i = ft_strlen(s) - start;
	if (i > len)
		i = len;
	if (start > ft_strlen(s))
	{
		result = ft_calloc(1, sizeof(char));
		if (result)
			return (result);
		else
			return (NULL);
	}
	result = ft_calloc(i + 1, sizeof(char));
	if (result)
		ft_strlcpy(result, (s + start), i + 1);
	else
		return (NULL);
	return (result);
}
