/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 21:36:25 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/06/24 23:02:38 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	show_square(t_dlx **root)
{
	char	*map;
	size_t	i;

	i = 0;
	map = ft_strnew(((*root)->square + 1) * (*root)->square);
	ft_memset(map, '.', ((*root)->square + 1) * (*root)->square);
	while (i < ((*root)->square + 1) * (*root)->square)
	{
		if (!((i + 1) % ((*root)->square + 1)))
			map[i] = '\n';
		i++;
	}
	while (*root)
	{
		i = 4;
		while (i-- > 0)
			map[((*root)->block.y[i] * ((*root)->square + 1)) + \
				(*root)->block.x[i]] = (*root)->letter;
		*root = (*root)->left;
	}
	ft_putstr(map);
	ft_strdel(&map);
}

int		pars_input_file(char *line, t_dlx **root)
{
	static size_t	line_counter;
	static size_t	empty_line;
	int				res;

	res = check_line(line);
	if (res == 1)
	{
		if (line_counter / 4 != empty_line)
			return (0);
		if (!(line_counter % 4))
			if (!create_dlx_node(root))
				return (0);
		if (!fill_dlx_node(*root, line, line_counter++ % 4))
			return (0);
	}
	else if (res == -1)
		return (0);
	else if (res == 0)
		empty_line++;
	return (1);
}

void	ft_error(int error)
{
	if (error == 0)
		ft_putendl("error");
	else if (error == -1)
		ft_putendl("usage: fillit input_file");
	exit(0);
}

int		main(int argc_aka_crutch, char **argv)
{
	int		fd;
	char	*line;
	t_dlx	*root;

	if (argc_aka_crutch != 2)
		ft_error(-1);
	if ((fd = open(argv[1], O_RDONLY)) < 1)
		ft_error(0);
	root = NULL;
	line = NULL;
	while (get_next_line(fd, &line))
	{
		if (!pars_input_file(line, &root))
		{
			clean_dlx(root, 2);
			ft_error(0);
		}
		argc_aka_crutch = ft_strlen(line);
		ft_strdel(&line);
	}
	if (!root || !argc_aka_crutch)
		ft_error(0);
	build_square(&root);
	return (0);
}
