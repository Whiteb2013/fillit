/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 21:01:57 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/04/21 19:57:30 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const char	*sp;
	char		*dp;

	sp = src;
	dp = dst;
	while (n--)
		if ((unsigned char)(*dp++ = *sp++) == (unsigned char)c)
			return (dp);
	return (NULL);
}
