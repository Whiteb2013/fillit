/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tetrimino.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 22:06:54 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/06/29 15:43:50 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	move_top(t_dlx *node)
{
	size_t i;

	if (node->block.y[0])
	{
		i = 4;
		while (i--)
			node->block.y[i]--;
		move_top(node);
	}
}

void	move_left(t_dlx *node)
{
	size_t i;

	i = 0;
	while (i < 4)
	{
		if (!node->block.x[i])
			return ;
		i++;
	}
	while (i--)
		node->block.x[i]--;
	move_left(node);
}

void	move_right(t_dlx *node)
{
	size_t i;

	i = 4;
	while (i--)
	{
		node->block.y[i] = node->up->block.y[i];
		node->block.x[i] = node->up->block.x[i] + 1;
	}
}

void	move_down(t_dlx *node)
{
	size_t i;

	i = 4;
	while (i--)
	{
		node->block.x[i] = node->up->block.x[i];
		node->block.y[i] = node->up->block.y[i] + 1;
	}
	move_left(node);
}

void	move_tetrimino(t_dlx *node, int offset)
{
	if (offset == 1)
		move_right(node);
	else if (offset == 2)
		move_down(node);
	else if (offset == 3)
		move_top(node);
	else if (offset == 4)
		move_left(node);
}
