/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 21:36:25 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/05/22 23:47:58 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

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
			return (0);
		line = NULL;
		line_counter = 0;
		if (!(root = (t_dlx *)ft_memalloc(sizeof(t_dlx))))
		{
			ft_putendl("error");
			return (0);
		}
		while (get_next_line(fd, &line) > 0)
		{
			/*entry check
			 * if (!(check_next_line(line)))
			 * ft_putendl("error");*/
			if (ft_strlen(line))
			{
				if (++line_counter % 4 == 1)
					create_dlx_node(&root, line);
				else
					fill_dlx_node(&root, line);
			}
			ft_strdel(&line);
		}
		/*show_square(root);*/
	}
	return (0);
}
