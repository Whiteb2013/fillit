/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlx_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 14:26:52 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/06/13 22:47:37 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

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
