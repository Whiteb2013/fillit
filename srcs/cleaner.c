/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 15:26:16 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/06/29 15:36:03 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	clean_dlx_base(t_dlx *root)
{
	if (!root)
		return ;
	if (root->right)
	{
		root->right->left = NULL;
		clean_dlx_base(root->right);
	}
	root->right = NULL;
	free(root);
}

void	clean_dlx_options(t_dlx *root)
{
	if (root->down)
		clean_dlx_options(root->down);
	if (root->up)
	{
		root->up->down = NULL;
		root->up = NULL;
		root->left = NULL;
		root->right = NULL;
		free(root);
	}
	else if (root->right)
		clean_dlx_options(root->right);
}

void	clean_dlx(t_dlx *node, int mode)
{
	if (!node)
		return ;
	while (node->left)
		node = node->left;
	while (node->up)
		node = node->up;
	if (mode == 1)
		clean_dlx_options(node);
	if (mode == 2)
	{
		clean_dlx_options(node);
		clean_dlx_base(node);
	}
}
