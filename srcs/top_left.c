/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_left.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 22:06:54 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/06/24 22:36:39 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		square_checker(t_dlx *node)
{
	size_t	i;
	int		offset;

	i = 4;
	offset = 2;
	while (i-- > 0 && offset != 1)
		if (node->block.x[i] + 1 >= node->side)
			offset = 1;
	if (node->block.y[3] >= node->side)
		return (0);
	if (offset == 1 && node->block.y[3] + 1 >= node->side)
		return (0);
	return (offset);
}

void	move_top(t_dlx *root)
{
	size_t i;

	if (root->block.y[0])
	{
		i = 0;
		while (i < 4)
		{
			root->block.y[i]--;
			i++;
		}
		move_top(root);
	}
}

void	move_left(t_dlx *root)
{
	size_t i;

	i = 0;
	while (i < 4)
	{
		if (!root->block.x[i])
			return ;
		i++;
	}
	while (i-- > 0)
		root->block.x[i]--;
	move_left(root);
}
