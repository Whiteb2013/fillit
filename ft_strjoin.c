/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 20:24:45 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/04/17 23:14:16 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *str;

	if (s1)
	{
		if (s2)
		{
			if ((str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))) == NULL)
				return (NULL);
			else
				return (ft_strcat(ft_strcat(str, s1), s2));
		}
		return (ft_strdup(s1));
	}
	return (NULL);
}
