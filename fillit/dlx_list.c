/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlx_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 14:26:52 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/06/15 17:55:11 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		create_dlx_node_down(t_dlx *node, size_t square)
{
	t_dlx	*tmp;
	size_t	i;
	int		offset;

	tmp = node;
	i = 0;
	if (!(offset = square_checker(tmp, square)))
		return (0);
	while (tmp->down)
		tmp = tmp->down;
	if (!(tmp->down = (t_dlx *)ft_memalloc(sizeof(t_dlx))))
		return (-1);
	tmp->down->right = NULL;
	tmp->down->left = NULL;
	tmp->down->down = NULL;
	tmp->down->up = tmp;
	tmp->down->square = square;
	if (offset == 2)
		while (i-- > 0)
			tmp->down->pos.x[i] = tmp->pos.x[i] + 1;
	else if (offset == 1)
	{
		move_left(&tmp->down);
		while (i-- > 0)
			tmp->down->pos.y[i] = tmp->pos.y[i] + 1;
	}
	return (1);
}

t_dlx	**create_dlx_node(t_dlx **root, char c)
{
	t_dlx	*tmp;

	if (!root)
		return (NULL);
	while ((*root)->right)
		*root = (*root)->right;
	if (!(tmp = (t_dlx *)ft_memalloc(sizeof(t_dlx))))
		return (NULL);
	tmp->right = NULL;
	tmp->down = NULL;
	tmp->up = NULL;
	tmp->pos.letter = c;
	tmp->pos.amount = 0;
	(*root)->right = tmp;
	tmp->left = *root;
	return (root);
}

void	fill_dlx_node(t_dlx **root, char *s, size_t y)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '#')
		{
			(*root)->pos.y[(*root)->pos.amount] = y;
			(*root)->pos.x[(*root)->pos.amount] = i;
			(*root)->pos.amount++;
		}
		i++;
	}
	if ((*root)->pos.amount == 4)
	{
		move_top(root);
		move_left(root);
	}
}
