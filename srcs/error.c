/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 21:28:39 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/06/29 15:34:03 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(int error)
{
	if (error == 0)
		ft_putendl("error");
	else if (error == -1)
		ft_putendl("usage: fillit input_file");
	exit(0);
}

void	ft_error_dlx(t_dlx *node)
{
	clean_dlx(node, 2);
	ft_error(0);
}
