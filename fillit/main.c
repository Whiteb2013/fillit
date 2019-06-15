/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 21:36:25 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/06/15 17:55:22 by lgeorgin         ###   ########.fr       */
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
			return (ft_error_display(0));
		if (!(root = (t_dlx *)ft_memalloc(sizeof(t_dlx))))
			return (ft_error_display(0));
		line = NULL;
		line_counter = 0;
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
					if (!create_dlx_node(&root, c++))
						return (ft_error_display(0));	
				printf("Filling node %p\n", root);
				fill_dlx_node(&root, line, line_counter % 4);
				line_counter++;
			}
			ft_strdel(&line);
		}
		//1)calculate estimated square 2)try to resolve 3)print on screen
		show_square(&root);
	}
	return (0);
}
