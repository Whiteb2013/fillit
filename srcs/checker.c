/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 17:20:22 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/06/29 15:24:48 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_line(char *line)
{
	size_t	len;

	if ((len = ft_strlen(line)))
	{
		if (len == 4)
		{
			while (len--)
				if (line[len] != '.' && line[len] != '#')
					ft_error(0);
		}
		else
			ft_error(0);
	}
	else
		return (0);
	return (1);
}

int		check_tetrimino(t_dlx *node)
{
	size_t	i;
	size_t	k;
	size_t	sum;

	if (node->block.amount != 4)
		ft_error(0);
	sum = 0;
	i = 4;
	while (i--)
	{
		k = i;
		while (k--)
		{
			if (node->block.x[i] == node->block.x[k] \
					&& node->block.y[i] == node->block.y[k] + 1)
				sum++;
			if (node->block.x[i] == node->block.x[k] + 1 \
					&& node->block.y[i] == node->block.y[k])
				sum++;
		}
	}
	return (sum > 2);
}

int		check_space_for_option(t_dlx *node)
{
	size_t	i;
	int		offset;

	i = 4;
	offset = 1;
	while (i-- && offset != 2)
		if (node->block.x[i] + 1 >= node->side)
			offset = 2;
	if (node->block.y[3] >= node->side)
		return (0);
	if (offset == 2 && node->block.y[3] + 1 >= node->side)
		return (0);
	return (offset);
}

int		check_dlx_left(t_dlx *node)
{
	t_dlx	*tmp;
	size_t	i;
	size_t	k;

	tmp = node->left;
	while (tmp)
	{
		i = 4;
		while (i--)
		{
			k = 4;
			while (k--)
			{
				if (tmp->block.x[i] == node->block.x[k] \
						&& tmp->block.y[i] == node->block.y[k])
					return (0);
			}
		}
		tmp = tmp->left;
	}
	free(tmp);
	return (1);
}
