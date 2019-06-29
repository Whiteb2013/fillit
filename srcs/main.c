/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 21:36:25 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/06/29 15:52:00 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	show_square(t_dlx **root)
{
	char	*square;
	size_t	i;
	t_dlx	*tmp;

	i = 0;
	square = ft_strnew(((*root)->side + 1) * (*root)->side);
	ft_memset(square, '.', ((*root)->side + 1) * (*root)->side);
	while (i < ((*root)->side + 1) * (*root)->side)
	{
		if (!((i + 1) % ((*root)->side + 1)))
			square[i] = '\n';
		i++;
	}
	tmp = *root;
	while (*root)
	{
		i = 4;
		while (i--)
			square[((*root)->block.y[i] * ((*root)->side + 1)) + \
				(*root)->block.x[i]] = (*root)->letter;
		*root = (*root)->left;
	}
	ft_putstr(square);
	ft_strdel(&square);
	clean_dlx(tmp, 2);
}

void	build_square(t_dlx **root)
{
	size_t size;
	size_t min_side;

	size = dlx_size(root);
	if ((min_side = ft_sqrt_plus(size * 4)) < (*root)->side)
		min_side = (*root)->side;
	while (!resolve_dlx(root, min_side++))
		clean_dlx(*root, 1);
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
			ft_error_dlx(*root);
		if (!(line_counter % 4))
			create_dlx_node_right(root);
		fill_dlx_node(*root, line, line_counter++ % 4);
	}
	else if (res == 0)
		empty_line++;
	else if (res == -1)
		ft_error_dlx(*root);
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
		ft_error_dlx(root);
	build_square(&root);
	show_square(&root);
	return (0);
}
