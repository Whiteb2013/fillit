/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 22:27:31 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/04/14 23:00:54 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(unsigned int n)
{
	unsigned int i;

	i = 0;
	while ((n = n / 10) > 0)
		i++;
	return (++i);
}

char		*ft_itoa(int n)
{
	char			*str;
	size_t			length;
	unsigned int	digit;
	size_t			sign;

	sign = 0;
	if (n < 0)
	{
		sign = 1;
		digit = -n;
	}
	else
		digit = n;
	length = count(digit);
	if ((str = ft_strnew(length + sign)) == NULL)
		return (NULL);
	if (sign == 1)
		str[0] = '-';
	while (digit / 10 > 0)
	{
		str[length-- + sign - 1] = digit % 10 + '0';
		digit = digit / 10;
	}
	str[length + sign - 1] = digit % 10 + '0';
	return (str);
}
