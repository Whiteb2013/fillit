/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 21:50:51 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/06/29 15:51:58 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	gen_dlx_options(t_dlx **root, size_t side)
{
	t_dlx	*tmp;

	tmp = *root;
	while (tmp)
	{
		tmp->side = side;
		while (create_dlx_node_down(tmp))
			;
		tmp = tmp->right;
	}
}

int		build_dlx_chain(t_dlx **node)
{
	if (check_dlx_left(*node))
	{
		if ((*node)->right)
			(*node)->right->left = *node;
		*node = (*node)->right;
	}
	else if ((*node)->down)
	{
		(*node)->down->left = (*node)->left;
		*node = (*node)->down;
	}
	else
	{
		while ((*node)->left && !(*node)->left->down)
			*node = (*node)->left;
		if ((*node)->left && (*node)->left->down)
		{
			(*node)->left->down->left = (*node)->left->left;
			*node = (*node)->left->down;
		}
		else
			return (0);
	}
	return (1);
}

int		resolve_dlx(t_dlx **root, size_t side)
{
	t_dlx	*tmp;
	t_dlx	*tmp_prev;

	tmp = *root;
	gen_dlx_options(root, side);
	while (tmp)
	{
		tmp_prev = tmp;
		if (!(build_dlx_chain(&tmp)))
			return (0);
	}
	*root = tmp_prev;
	return (1);
}
