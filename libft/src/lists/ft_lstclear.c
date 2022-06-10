/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:49:09 by fleblanc          #+#    #+#             */
/*   Updated: 2022/04/08 18:36:02 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*buf;

	buf = *lst;
	while (buf != NULL)
	{
		tmp = buf->next;
		ft_lstdelone(buf, del);
		buf = tmp;
	}
	*lst = NULL;
}
