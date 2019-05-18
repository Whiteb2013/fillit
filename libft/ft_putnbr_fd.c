/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 00:22:43 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/04/15 18:41:57 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	i;

	if (fd > 0)
	{
		if (n < 0)
		{
			i = -n;
			ft_putchar_fd('-', fd);
		}
		else
			i = n;
		if (i > 9)
			ft_putnbr_fd((int)(i / 10), fd);
		ft_putchar_fd(i % 10 + '0', fd);
	}
}
