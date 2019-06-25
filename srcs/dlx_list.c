/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlx_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 14:26:52 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/06/24 22:59:01 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		create_dlx_node_down(t_dlx *node)
{
	t_dlx	*tmp;
	int		i;
	int		offset;

	tmp = node;
	i = 4;
	while (tmp->down)
		tmp = tmp->down;
	if (!(offset = square_checker(tmp)))
		return (0);
	if (!(tmp->down = (t_dlx *)ft_memalloc(sizeof(t_dlx))))
		return (-1);
	tmp->down->right = tmp->right;
	tmp->down->left = NULL;
	tmp->down->down = NULL;
	tmp->down->up = tmp;
	tmp->down->square = tmp->square;
	tmp->down->letter = tmp->letter;
	if (offset == 2)
		while (i-- > 0)
		{
			tmp->down->block.y[i] = tmp->block.y[i];
			tmp->down->block.x[i] = tmp->block.x[i] + 1;
		}
	else if (offset == 1)
	{
		while (i-- > 0)
		{
			tmp->down->block.x[i] = tmp->block.x[i];
			tmp->down->block.y[i] = tmp->block.y[i] + 1;
		}
		move_left(tmp->down);
	}
	return (1);
}

t_dlx	**create_dlx_node(t_dlx **root)
{
	t_dlx	*tmp;

	if (!(tmp = (t_dlx *)ft_memalloc(sizeof(t_dlx))))
		return (NULL);
	tmp->right = NULL;
	tmp->down = NULL;
	tmp->up = NULL;
	tmp->block.amount = 0;
	if (!*root)
	{
		*root = tmp;
		tmp->letter = 'A';
	}
	else
	{
		while ((*root)->right)
			*root = (*root)->right;
		tmp->left = *root;
		tmp->letter = (*root)->letter + 1;
		(*root)->right = tmp;
		*root = (*root)->right;
	}
	return (root);
}

int		fill_dlx_node(t_dlx *root, char *s, size_t y)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '#')
		{
			if (root->block.amount == 4)
				return (0);
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
			root->square = root->block.x[3] + 1;
		else
			root->square = root->block.y[3] + 1;
	}
	return (1);
}
