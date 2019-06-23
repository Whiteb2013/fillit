/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 15:26:16 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/06/23 18:04:20 by lgeorgin         ###   ########.fr       */
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

void	clean_dlx(t_dlx *root, int mode)
{
	if (!root)
		return ;
	while (root->left)
		root = root->left;
	while (root->up)
		root = root->up;
	if (mode == 1)
		clean_dlx_options(root);
	if (mode == 2)
	{
		clean_dlx_options(root);
		clean_dlx_base(root);
	}
}
