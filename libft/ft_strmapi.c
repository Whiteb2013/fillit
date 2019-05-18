/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 19:30:14 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/04/20 00:08:44 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	counter;
	unsigned int	length;
	char			*str;

	if (s && f)
	{
		counter = 0;
		length = ft_strlen(s);
		if (!(str = ft_strnew(length)))
			return (NULL);
		while (length--)
		{
			str[counter] = f(counter, s[counter]);
			counter++;
		}
		return (str);
	}
	else
		return (NULL);
}
