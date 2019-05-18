/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 01:14:04 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/04/21 23:51:43 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strclean(char **str, size_t len)
{
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	while (i < len)
	{
		ft_strdel(&str[i]);
		i++;
	}
	free(str);
	return (str);
}
