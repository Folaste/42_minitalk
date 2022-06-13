/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 10:58:40 by fleblanc          #+#    #+#             */
/*   Updated: 2022/04/13 16:48:18 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static int	ft_count_words(char const *s, char c)
{
	size_t	i;
	int		nb_words;
	int		word;

	word = 0;
	i = 0;
	nb_words = 0;
	while (s[i])
	{
		if (word == 0 && s[i] != c)
		{
			word = 1;
			nb_words++;
		}
		else if (word == 1 && s[i] == c)
			word = 0;
		i++;
	}
	return (nb_words);
}

static char	*ft_fill_tab(char *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] == c)
		i++;
	while (s[i + j] && s[i + j] != c)
		j++;
	return (ft_substr(s, i, j));
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		nb_words;
	int		index;
	char	*s_copy;

	if (!s)
		return (NULL);
	s_copy = (char *)s;
	index = 0;
	nb_words = ft_count_words(s, c);
	tab = ft_calloc(nb_words + 1, sizeof(char *));
	if (tab == NULL)
		return (NULL);
	while (index < nb_words)
	{
		while (*s_copy == c)
			s_copy++;
		tab[index] = ft_fill_tab(s_copy, c);
		if (tab[index] == NULL)
			return (NULL);
		s_copy += ft_strlen(tab[index]);
		index++;
	}
	tab[index] = NULL;
	return (tab);
}
