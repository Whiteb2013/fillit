/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 17:49:21 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/04/20 18:13:04 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	length;
	char	*dst;

	length = ft_strlen(s1);
	if (n > length)
		n = length;
	if (!(dst = ft_strnew(n)))
		return (NULL);
	dst[n] = '\0';
	while (n--)
		dst[n] = s1[n];
	return (dst);
}
