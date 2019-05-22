/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 22:05:37 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/05/01 20:15:53 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_del(void *content, size_t size)
{
	(void)size;
	free(content);
}

static	t_list	*ft_clean(t_list *alst)
{
	void	(*del)(void *, size_t);

	del = ft_del;
	ft_lstdel(&alst, del);
	return (alst);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *alst;
	t_list *first;

	if (!lst || !f)
		return (NULL);
	tmp = f(lst);
	if (!(alst = ft_lstnew(tmp->content, tmp->content_size, tmp->fd)))
		return (NULL);
	first = alst;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		if (!(alst->next = ft_lstnew(tmp->content, tmp->content_size, tmp->fd)))
			return (ft_clean(first));
		alst = alst->next;
		lst = lst->next;
	}
	return (first);
}
