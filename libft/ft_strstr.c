/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:37:23 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/04/20 01:52:33 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	char *src_str;
	char *to_find_copy;

	if (!(to_find_copy = ft_strdup(to_find)))
		return (NULL);
	if (!*to_find)
		return ((char *)str);
	while (*str)
	{
		if (*str == *to_find_copy)
		{
			if (!(src_str = ft_strdup(str)))
				return (NULL);
			while (*src_str == *to_find_copy || *to_find_copy == '\0')
			{
				if (*to_find_copy == '\0')
					return ((char *)str);
				to_find_copy++;
				src_str++;
			}
			to_find_copy = ft_strcpy(to_find_copy, to_find);
		}
		str++;
	}
	return (0);
}
