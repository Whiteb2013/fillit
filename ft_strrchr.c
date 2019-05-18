/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 21:22:33 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/04/20 01:57:07 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t size;

	size = 0;
	while (*s)
	{
		s++;
		size++;
	}
	while (*s != (char)c)
	{
		if (size-- == 0)
			return (0);
		s--;
	}
	return ((char *)s);
}
