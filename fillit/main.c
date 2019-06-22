/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 21:36:25 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/06/22 15:25:53 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	show_square(t_dlx *root)
{
	char	*map;
	size_t	i;

	i = 0;
	map = ft_strnew((root->square + 1) * root->square);
	ft_memset(map, '.', (root->square + 1) * root->square);
	while (i < (root->square + 1) * root->square)
	{
		if (!((i + 1) % (root->square + 1)))
			map[i] = '\n';
		i++;
	}
	while (root)
	{	
		i = 4;
		while (i-- > 0)
		{
			map[(root->pos.y[i] * (root->square + 1)) + \
				root->pos.x[i]] = root->letter;
		}
		root = root->left;
	}
	ft_putstr(map);
	ft_strdel(&map);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	t_dlx	*root;
	size_t	line_counter;

	if (argc != 2)
		ft_putendl("usage: cp source_file");
	else
	{
		if ((fd = open(argv[1], O_RDONLY)) < 1)
			return (ft_error_display(0));
		//if (!(root = (t_dlx *)ft_memalloc(sizeof(t_dlx))))
		//	return (ft_error_display(0));
		//root = NULL;
		line = NULL;
		line_counter = 0;
		while (get_next_line(fd, &line) > 0)
		{
			/*entry check
			 * if (!(check_next_line(line)))
			 * ft_putendl("error");*/
			if (ft_strlen(line))
			{	
				if (!(line_counter % 4))
					if (!create_dlx_node(&root))
						return (ft_error_display(0));	
				fill_dlx_node(root, line, line_counter % 4);
				line_counter++;
			}
			ft_strdel(&line);
		}
		if (calc_square(&root) == 1)
			show_square(root);
		else
			return (ft_error_display(0));
	}
	return (0);
}
