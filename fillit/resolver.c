/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 21:50:51 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/06/20 23:11:20 by lgeorgin         ###   ########.fr       */
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
	t_dlx	*tmp2;
	int 	res;
	size_t	i = 0;
	size_t	x = 0;
	size_t	y = 0;
	size_t	pointer = 0;

	tmp = *root;
	while (tmp)
	{
		printf("New tetrimino %p\n", tmp);
		while ((res = create_dlx_node_down(tmp, square)) > 0)
			;
		if (res < 0)
			return (0);
		//printing to check
		tmp2 = tmp;
		while (tmp2)
		{
			printf("%p\n",tmp2);
			y = 0;
			while (y < square)
			{
				x = 0;
				while (x < square)
				{
					i = 0;
					pointer = 0;
					while (i < 4)
					{
						if (tmp2->pos.x[i] == x && tmp2->pos.y[i] == y)
							pointer = 1;
						i++;
					}
					if (!pointer)
						printf(".");
					else
						printf("#");
					x++;
				}
				printf("\n");
				y++;
			}
			printf("\n");
			tmp2 = tmp2->down;
		}
		//till here
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
				if (tmp->pos.x[i] == node->pos.x[k] 
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
			tmp = tmp->down;
		else
		{
			while (tmp->left && !tmp->left->down)
				tmp = tmp->left;
			if (tmp->left && tmp->left->down)
				tmp = tmp->left->down;
			else
				return (0);
		}
	}
	*root = tmp_prev;
	return (1);
}

int		show_square(t_dlx **root)
{
	size_t min_square;

	min_square = ft_sqrt_plus(dlx_size(root) * 4);	
	//if (!gen_dlx_options(root, min_square))
	//	return (ft_error_display(0));
	while (!resolve_dlx(root, min_square))
		min_square++;
	printf("Final position %p", *root);
	return (1);
}
