/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlx_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 14:26:52 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/06/28 23:53:27 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		create_dlx_node_down(t_dlx *node)
{
	int		i;
	int		offset;

	i = 4;
	while (node->down)
		node = node->down;
	if (!(offset = square_checker(node)))
		return (0);
	if (!(node->down = (t_dlx *)ft_memalloc(sizeof(t_dlx))))
		ft_error(0);
	node->down->right = node->right;
	node->down->left = NULL;
	node->down->down = NULL;
	node->down->up = node;
	node->down->side = node->side;
	node->down->letter = node->letter;
	if (offset == 2)
		while (i-- > 0)
		{
			node->down->block.y[i] = node->block.y[i];
			node->down->block.x[i] = node->block.x[i] + 1;
		}
	else if (offset == 1)
	{
		while (i-- > 0)
		{
			node->down->block.x[i] = node->block.x[i];
			node->down->block.y[i] = node->block.y[i] + 1;
		}
		move_left(node->down);
	}
	return (1);
}

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
			ft_error(0);
		(*root)->right->left = *root;
		(*root)->right->letter = (*root)->letter + 1;
		(*root) = (*root)->right;
	}
	(*root)->right = NULL;
	(*root)->down = NULL;
	(*root)->up = NULL;
	(*root)->block.amount = 0;
}

void	fill_dlx_node(t_dlx *root, char *s, size_t y)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '#')
		{
			if (root->block.amount == 4)
				ft_error(0);
			root->block.y[root->block.amount] = y;
			root->block.x[root->block.amount] = i;
			root->block.amount++;
		}
		i++;
	}
	if (root->block.amount == 4)
	{
		move_top(root);
		move_left(root);
		if (root->block.x[3] > root->block.y[3])
			root->side = root->block.x[3] + 1;
		else
			root->side = root->block.y[3] + 1;
	}
}
