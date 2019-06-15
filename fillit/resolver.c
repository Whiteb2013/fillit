/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 21:50:51 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/06/15 17:55:20 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

size_t	dlx_size(t_dlx **root)
{	
	size_t size;

	size = 0;
	while ((*root)->left)
	{	
		size++;
		*root = (*root)->left;
	}	
	return (size + 1);
}

int		gen_dlx_options(t_dlx **root, size_t square)
{
	t_dlx	*tmp;
	int 	res;

	tmp = *root;
	//find out, why last tmp has right link. Should be while (tmp) instead
	while (tmp->right)
	{
		printf("Listing %p", tmp);
		while ((res = create_dlx_node_down(tmp, square)) > 0)
			;
		if (res < 0)
			return (0);
		tmp = tmp->right;
	}
	return (1);
}

int		show_square(t_dlx **root)
{
	size_t min_square;
	size_t size;

	size = dlx_size(root);
	printf("Size = %zu\n", size);
	min_square = ft_sqrt_plus(size * 4);	
	printf("min_square = %zu\n", min_square);
	if (!gen_dlx_options(root, min_square))
		return (ft_error_display(0));
	return (1);
}
