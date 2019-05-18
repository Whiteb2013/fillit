/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 18:49:10 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/04/20 00:08:07 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	size;

	if (s && f)
	{
		size = ft_strlen(s);
		if (!(str = ft_strnew(size)))
			return (NULL);
		while (size-- && s[size])
			str[size] = f(s[size]);
		return (str);
	}
	else
		return (NULL);
}
