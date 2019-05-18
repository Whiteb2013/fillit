/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 00:26:11 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/04/13 01:16:32 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while ((*(unsigned char *)s1++ == *(unsigned char *)s2) && --n)
		if (*(s2++) == 0)
			return (0);
	return (*(unsigned char *)--s1 - *(unsigned char *)s2);
}
