/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 20:36:36 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/06/29 15:51:14 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef	struct		s_block
{
	size_t			x[4];
	size_t			y[4];
	size_t			amount;
}					t_block;

typedef	struct		s_dlx
{
	size_t			side;
	char			letter;
	t_block			block;
	struct s_dlx	*up;
	struct s_dlx	*down;
	struct s_dlx	*right;
	struct s_dlx	*left;
}					t_dlx;

void				create_dlx_node_right(t_dlx **root);
int					create_dlx_node_down(t_dlx *node);
void				fill_dlx_node(t_dlx *node, char *s, size_t y);
size_t				dlx_size(t_dlx **root);
int					resolve_dlx(t_dlx **root, size_t size);
void				move_tetrimino(t_dlx *node, int offset);
int					check_space_for_option(t_dlx *node);
int					check_line(char *line);
int					check_tetrimino(t_dlx *node);
int					check_dlx_left(t_dlx *node);
size_t				ft_sqrt_plus(size_t nb);
void				ft_error(int error);
void				ft_error_dlx(t_dlx *node);
void				clean_dlx(t_dlx *node, int mode);

#endif
