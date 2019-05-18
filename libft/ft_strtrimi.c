/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 13:17:30 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/04/20 00:44:09 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrimi(char const *s, char const c)
{
	size_t	start;
	size_t	end;
	char	*dest;

	start = 0;
	if (s && (end = ft_strlen(s)))
	{
		while (s[start] == c)
			start++;
		while (start < --end && (s[end] == c))
			;
	}
	if (s && start != end)
	{
		if (!(dest = ft_strnew(end - start + 1)))
			return (NULL);
		ft_strncpy(dest, &s[start], end - start + 1);
	}
	else
	{
		if (!s || !(dest = ft_strnew(0)))
			return (NULL);
	}
	return (dest);
}
