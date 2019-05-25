/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 20:36:36 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/05/25 19:10:00 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/get_next_line.h"
# include <fcntl.h>

typedef	struct		s_point
{
	size_t			*x;
	size_t			*y;
	size_t			amount;
	char			letter;
}					t_point;

typedef	struct		s_dlx
{
	size_t			square;
	t_point			pos;
	struct s_dlx	*up;
	struct s_dlx	*down;
	struct s_dlx	*right;
	struct s_dlx	*left;
}					t_dlx;

t_dlx	**create_dlx_node(t_dlx **root, char c);
void	fill_dlx_node(t_dlx **root, char *s, size_t y);

#endif
