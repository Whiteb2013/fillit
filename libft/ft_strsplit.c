/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 19:08:12 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/04/20 01:43:17 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	char	*s1;
	size_t	i;
	int		j;
	size_t	k;

	j = -1;
	if (!s || (!(s1 = ft_strnew(ft_strlen(s)))))
		return (NULL);
	s1 = ft_strtrimi(s, c);
	i = ft_strwordcounter(s1, c);
	if ((str = (char **)ft_memalloc(sizeof(char *) * (i + 1))) == NULL)
		return (NULL);
	while (++j - i)
	{
		if ((str[j] = ft_strnew(ft_strwordsize(s1, c))) == NULL)
			return (ft_strclean(str, j));
		k = 0;
		while (*s1 != c && *s1)
			str[j][k++] = *s1++;
		while (*s1 == c)
			s1++;
	}
	str[i] = 0;
	return (str);
}
