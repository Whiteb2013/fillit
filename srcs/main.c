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
	char	*square;
	size_t	i;

	i = 0;
	square = ft_strnew(((*root)->side + 1) * (*root)->side);
	ft_memset(square, '.', ((*root)->side + 1) * (*root)->side);
	while (i < ((*root)->side + 1) * (*root)->side)
	{
		if (!((i + 1) % ((*root)->side + 1)))
			square[i] = '\n';
		i++;
	}
	while (*root)
	{
		i = 4;
		while (i-- > 0)
			square[((*root)->block.y[i] * ((*root)->side + 1)) + \
				(*root)->block.x[i]] = (*root)->letter;
		*root = (*root)->left;
	}
	ft_putstr(square);
	ft_strdel(&square);
}

void	pars_input_file(char *line, t_dlx **root)
{
	static size_t	line_counter;
	static size_t	empty_line;
	int				res;

	res = check_line(line);
	if (res == 1)
	{
		if (line_counter / 4 != empty_line)
			ft_error(0);
		if (!(line_counter % 4))
			create_dlx_node(root);
		fill_dlx_node(*root, line, line_counter++ % 4);
	}
	else if (res == 0)
		empty_line++;
	else if (res == -1)
		ft_error(0);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	t_dlx	*root;
	char	flag;

	if (argc != 2)
		ft_error(-1);
	if ((fd = open(argv[1], O_RDONLY)) < 1)
		ft_error(0);
	root = NULL;
	line = NULL;
	while (get_next_line(fd, &line))
	{
		flag = 'f';
		pars_input_file(line, &root);
		if (line[0] == '\0')
			flag = 't';
		ft_strdel(&line);
	}
	if (!root || flag == 't')
		ft_error(0);
	build_square(&root);
	return (0);
}
