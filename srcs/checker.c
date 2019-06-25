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

	if (node->block.amount != 4)
		return (0);
	sum = 0;
	i = 4;
	while (i--)
	{
		k = i;
		while (k--)
		{
			if (node->block.x[i] == node->block.x[k] \
					&& node->block.y[i] == node->block.y[k] + 1)
				sum++;
			if (node->block.x[i] == node->block.x[k] + 1 \
					&& node->block.y[i] == node->block.y[k])
				sum++;
		}
	}
	return (sum > 2);
}
