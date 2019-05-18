/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 20:07:52 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/04/21 19:48:34 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	char *dp;

	dp = dest;
	while (*src && len)
	{
		*dp++ = *src++;
		len--;
	}
	while (len--)
		*dp++ = '\0';
	return (dest);
}
