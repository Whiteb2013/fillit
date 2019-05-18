/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 21:49:59 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/04/20 00:56:05 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		counter;
	size_t		i;
	const char	*buffer;
	const char	*src;

	counter = 0;
	if (!(buffer = (char *)ft_memalloc(sizeof(ft_strlen(needle) + 1)))
			|| !(src = (char *)ft_memalloc(sizeof(ft_strlen(haystack) + 1))))
		return (NULL);
	if (!*needle)
		return (char *)(haystack);
	while (*(haystack + counter) != '\0' && counter < len)
	{
		if (*(src = &(*(haystack + counter)))
				== *(buffer = &(*needle)))
		{
			i = counter;
			while (*buffer && *++src == *++buffer && ++i < len)
				;
			if (!*buffer)
				return (char *)(haystack + counter);
		}
		counter++;
	}
	return (NULL);
}
