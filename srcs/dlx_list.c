/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlx_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 14:26:52 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/06/29 15:37:11 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	create_dlx_node_right(t_dlx **root)
{
	if (!*root)
	{
		if (!(*root = (t_dlx *)ft_memalloc(sizeof(t_dlx))))
			ft_error(0);
		(*root)->letter = 'A';
		(*root)->left = NULL;
	}
	else
	{
		if (!((*root)->right = (t_dlx *)ft_memalloc(sizeof(t_dlx))))
			ft_error_dlx(*root);
		(*root)->right->left = *root;
		(*root)->right->letter = (*root)->letter + 1;
		(*root) = (*root)->right;
	}
	(*root)->right = NULL;
	(*root)->down = NULL;
	(*root)->up = NULL;
	(*root)->block.amount = 0;
}

int		create_dlx_node_down(t_dlx *node)
{
	size_t	i;
	int		offset;

	i = 4;
	while (node->down)
		node = node->down;
	if (!(offset = check_space_for_option(node)))
		return (0);
	if (!(node->down = (t_dlx *)ft_memalloc(sizeof(t_dlx))))
		ft_error_dlx(node);
	node->down->right = node->right;
	node->down->left = NULL;
	node->down->down = NULL;
	node->down->up = node;
	node->down->side = node->side;
	node->down->letter = node->letter;
	move_tetrimino(node->down, offset);
	return (1);
}

void	fill_dlx_node(t_dlx *node, char *s, size_t y)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '#')
		{
			if (node->block.amount == 4)
				ft_error_dlx(node);
			node->block.y[node->block.amount] = y;
			node->block.x[node->block.amount] = i;
			node->block.amount++;
		}
		i++;
	}
	if (node->block.amount == 4)
	{
		move_tetrimino(node, 3);
		move_tetrimino(node, 4);
		if (node->block.x[3] > node->block.y[3])
			node->side = node->block.x[3] + 1;
		else
			node->side = node->block.y[3] + 1;
	}
}

size_t	dlx_size(t_dlx **root)
{
	size_t size;
	size_t side;

	side = 0;
	size = 1;
	while ((*root)->left && check_tetrimino(*root))
	{
		size++;
		if (side < (*root)->side)
			side = (*root)->side;
		*root = (*root)->left;
	}
	if (side < (*root)->side)
		side = (*root)->side;
	(*root)->side = side;
	if (!check_tetrimino(*root) || size > 26)
		ft_error_dlx(*root);
	return (size);
}
