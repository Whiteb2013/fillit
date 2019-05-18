/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 01:32:44 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/04/20 17:53:35 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	length;
	char	*dst;

	length = ft_strlen(src);
	if (!(dst = ft_strnew(length)))
		return (NULL);
	while (length)
	{
		length--;
		dst[length] = src[length];
	}
	dst[length] = src[length];
	return (dst);
}
