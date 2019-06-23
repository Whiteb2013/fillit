/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 17:20:22 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/06/23 20:07:57 by lgeorgin         ###   ########.fr       */
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
					return (-1);
		}
		else
			return (-1);
	}
	else
		return (0);
	return (1);
}

//debug this
int		check_tetrimino(t_dlx *root)
{
	size_t i;
	size_t k;
	size_t sum;
	
	if (root->pos.amount != 4)
		return (0);
	i = 4;
	while (i--)
	{
		k = 0;
		sum = root->pos.x[i] + root->pos.y[i];
		while (k < 4 && root->pos.x[k] + root->pos.y[k] != sum + 1 &&
					root->pos.x[k] + root->pos.y[k] != sum - 1)
			k++;
		if (k == 4)
			return (0);
	}
	return (1);
}
