/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_left.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 22:06:54 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/06/15 17:55:17 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		square_checker(t_dlx *node, size_t square)
{
	size_t	i;
	int		offset;

	i = 0;
	offset = 2;
	while (i < 4 && offset != 1)
	{
		if (node->pos.x[i++] + 1 >= square)
		{
			i = 0;
			offset = 1;
		}
	}
	while (i < 4)
		if (node->pos.y[i++] + 1 >= square)
			return (0);
	return (offset);
}

void	move_top(t_dlx **root)
{
	size_t i;

	if ((*root)->pos.y[0])
	{
		i = 0;
		while (i < 4)
		{
			(*root)->pos.y[i]--;
			i++;
		}
		move_top(root);
	}
}

void	move_left(t_dlx **root)
{
	size_t i;

	i = 0;
	while (i < 4)
	{
		if (!(*root)->pos.x[i])
			return ;
		i++;
	}
	while (i-- > 0)
		(*root)->pos.x[i]--;
	move_left(root);
}
