/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 12:16:31 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/04/21 23:43:50 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long int	atoi;
	int			flag;

	atoi = 0;
	flag = 1;
	if (*str)
	{
		while ((*str > 8 && *str < 14) || *str == 32)
			str++;
		if (*str == 43 || *str == 45)
			flag = 44 - *str++;
		while (*str >= 48 && *str <= 57)
		{
			if (atoi * 10 / 10 < atoi && flag == 1)
				return (-1);
			else if (atoi * 10 / 10 > atoi && flag == -1)
				return (0);
			atoi = atoi * 10 + *str++ - 48;
		}
	}
	return ((int)(flag * atoi));
}
