/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 21:36:25 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/05/25 19:10:02 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	print(t_dlx *root)
{
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	t_dlx	*root;
	size_t	line_counter;
	char 	c;

	if (argc != 2)
		ft_putendl("usage: cp source_file");
	else
	{
		if ((fd = open(argv[1], O_RDONLY)) < 1)
			return (0);
		line = NULL;
		line_counter = 0;
		if (!(root = (t_dlx *)ft_memalloc(sizeof(t_dlx))))
		{
			ft_putendl("error");
			return (0);
		}
		c = 'A';
		while (get_next_line(fd, &line) > 0)
		{
			/*entry check
			 * if (!(check_next_line(line)))
			 * ft_putendl("error");*/
			printf("|%s|\n", line);
			if (ft_strlen(line))
			{
				if (!(line_counter % 4))
				{
					if (!create_dlx_node(&root, c++))
					{
						ft_putendl("error");
						return (0);
					}
				}
				fill_dlx_node(&root, line, line_counter % 4);
				line_counter++;
			}
			ft_strdel(&line);
		}
		printf("|x = %zu|y = %zu\n", root->pos.x[3], root->pos.y[3]);
		/*show_square(root);*/
	}
	return (0);
}
