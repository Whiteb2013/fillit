/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwordcounter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 01:28:32 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/04/20 01:48:25 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strwordcounter(const char *s, char c)
{
	size_t words;

	words = 0;
	if (!s || !*s)
		return (words);
	while (*s)
	{
		if (*s == c)
		{
			words++;
			while (*s == c)
				s++;
		}
		else
			s++;
	}
	return (++words);
}
