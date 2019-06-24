/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 17:20:22 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/06/24 21:23:16 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_line(char *line)
{
	size_t	len;

	if ((len = ft_strlen(line)))
	{
		if (len == 4)
		{
			while (len--)
				if (line[len] != '.' && line[len] != '#')
					return (-1);
		}
		else
			return (-1);
	}
	else
		return (0);
	return (1);
}

int		check_tetrimino(t_dlx *node)
{
	size_t	i;
	size_t	k;
	size_t	sum;

	if (node->pos.amount != 4)
		return (0);
	sum = 0;
	i = 4;
	while (i--)
	{
		k = i;
		while (k--)
		{
			if (node->pos.x[i] == node->pos.x[k] \
					&& node->pos.y[i] == node->pos.y[k] + 1)
				sum++;
			if (node->pos.x[i] == node->pos.x[k] + 1 \
					&& node->pos.y[i] == node->pos.y[k])
				sum++;
		}
	}
	return (sum > 2);
}
