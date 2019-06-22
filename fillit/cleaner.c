/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 15:26:16 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/06/22 18:01:10 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	clean_dlx_options(t_dlx *root)
{
	if (root->down)
		clean_dlx_options(root->down);
	else if (root->up)
	{
		root->up->down = NULL;
		printf("Cleaning %p\n", root);
		free(root);
	}
	else if (root->right)
		clean_dlx_options(root->right);
}
