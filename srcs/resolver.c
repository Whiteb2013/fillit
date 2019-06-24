/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 21:50:51 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/06/24 23:02:10 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	dlx_size(t_dlx **root)
{
	size_t size;
	size_t square;

	square = 0;
	size = 1;
	while ((*root)->left && check_tetrimino(*root))
	{
		size++;
		if (square < (*root)->square)
			square = (*root)->square;
		*root = (*root)->left;
	}
	(*root)->square = square;
	if (!check_tetrimino(*root) || size > 26)
		return (0);
	return (size);
}

int		gen_dlx_options(t_dlx **root, size_t square)
{
	t_dlx	*tmp;
	int		res;

	tmp = *root;
	while (tmp)
	{
		tmp->square = square;
		while ((res = create_dlx_node_down(tmp)) > 0)
			;
		if (res < 0)
			return (0);
		tmp = tmp->right;
	}
	return (1);
}

int		check_dlx_left(t_dlx *node)
{
	t_dlx	*tmp;
	int		i;
	int		k;

	tmp = node->left;
	while (tmp)
	{
		i = 4;
		while (i-- > 0)
		{
			k = 4;
			while (k-- > 0)
			{
				if (tmp->pos.x[i] == node->pos.x[k] \
						&& tmp->pos.y[i] == node->pos.y[k])
					return (0);
			}
		}
		tmp = tmp->left;
	}
	return (1);
}

int		resolve_dlx(t_dlx **root, size_t square)
{
	t_dlx	*tmp;
	t_dlx	*tmp_prev;

	tmp = *root;
	if (!gen_dlx_options(root, square))
		return (-1);
	while (tmp)
	{
		tmp_prev = tmp;
		if (check_dlx_left(tmp))
		{
			if (tmp->right)
				tmp->right->left = tmp;
			tmp = tmp->right;
		}
		else if (tmp->down)
		{
			tmp->down->left = tmp->left;
			tmp = tmp->down;
		}
		else
		{
			while (tmp->left && !tmp->left->down)
				tmp = tmp->left;
			if (tmp->left && tmp->left->down)
			{
				tmp->left->down->left = tmp->left->left;
				tmp = tmp->left->down;
			}
			else
				return (0);
		}
	}
	*root = tmp_prev;
	return (1);
}

void	build_square(t_dlx **root)
{
	size_t	size;
	size_t	min_square;
	int		res;

	if ((size = dlx_size(root)))
	{
		if ((min_square = ft_sqrt_plus(size * 4)) < (*root)->square)
			min_square = (*root)->square;
		while (!(res = resolve_dlx(root, min_square++)))
			clean_dlx(*root, 1);
		if (res > 0)
			show_square(root);
	}
	if (!size || res < 0)
	{
		clean_dlx(*root, 2);
		ft_error_display(0);
	}
}
