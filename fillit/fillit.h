/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 20:36:36 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/05/22 22:00:16 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "get_next_line.h"
# include <fcntl.h>

typedef	struct		s_dlx
{
	size_t			square;
	size_t			**pos;
	struct s_dlx	*up;
	struct s_dlx	*down;
	struct s_dlx	*right;
	struct s_dlx	*left;
}					t_dlx;

#endif
