/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 01:21:25 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/04/13 01:11:10 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*(unsigned char *)s1++ == *(unsigned char *)s2)
		if (*(s2++) == 0)
			return (0);
	return (*(unsigned char *)--s1 - *(unsigned char *)s2);
}
