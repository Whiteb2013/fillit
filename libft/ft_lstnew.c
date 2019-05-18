/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 19:57:19 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/04/15 20:46:59 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*tmp;

	if ((tmp = (t_list *)ft_memalloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (!content)
		content_size = 0;
	if (content_size)
	{
		if ((tmp->content = ft_memalloc(content_size * \
						sizeof(content))) == NULL)
		{
			free(tmp);
			return (NULL);
		}
		tmp->content = ft_memmove(tmp->content, content, content_size);
	}
	else
		tmp->content = NULL;
	tmp->content_size = content_size;
	tmp->next = NULL;
	return (tmp);
}
