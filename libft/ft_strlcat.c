/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:03:27 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/05/01 20:19:37 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t k;
	size_t buffer;

	if ((i = ft_strlen(dest)) >= size)
		buffer = ft_strlen(src) + size;
	else
	{
		buffer = ft_strlen(src) + i;
		k = i;
		while (i < size - 1 && src[i - k])
		{
			dest[i] = src[i - k];
			i++;
		}
		dest[i] = '\0';
	}
	return (buffer);
}
