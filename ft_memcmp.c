/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 22:21:43 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/04/10 23:29:34 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *s1p;
	const unsigned char *s2p;

	s1p = s1;
	s2p = s2;
	if (n == 0)
		return (0);
	while (--n)
	{
		if (*s1p - *s2p == 0)
		{
			s1p++;
			s2p++;
		}
	}
	return (*s1p - *s2p);
}
