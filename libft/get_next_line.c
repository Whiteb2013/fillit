/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 21:19:54 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/05/06 22:09:30 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_find_list(int fd, t_list **file_content)
{
	t_list			*tmp;

	tmp = *file_content;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(tmp = ft_lstnew("", 0, fd)))
		return (NULL);
	ft_lstadd(file_content, tmp);
	tmp = *file_content;
	return (tmp);
}

size_t			ft_strichr(char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i++] != (char)c)
		if (!s[i])
			return (0);
	return (i);
}

int				get_from_buffer(char **line, t_list *tmp, size_t i)
{
	char	*buf;

	if (!i)
	{
		if (!(*line = ft_strdup(tmp->content)))
			return (-1);
		tmp->content_size = 0;
	}
	else
	{
		if (!(*line = ft_strsub(tmp->content, 0, i - 1)))
			return (-1);
		if ((tmp->content_size = tmp->content_size - i) != 0)
			if (!(buf = ft_strsub(tmp->content, i, tmp->content_size)))
				return (-1);
	}
	ft_strdel((char **)&tmp->content);
	if (tmp->content_size)
	{
		tmp->content = ft_strdup(buf);
		ft_strdel(&buf);
	}
	return (1);
}

int				ft_read_file(int fd, t_list *tmp, char **line)
{
	char	buf[BUFF_SIZE + 1];
	int		res;
	size_t	i;
	char	*temp;

	i = 0;
	while (!i && (res = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[res] = '\0';
		i = ft_strichr(buf, '\n');
		temp = tmp->content;
		if (!(tmp->content = ft_strjoin(tmp->content, buf)))
		{
			ft_strdel((char **)&tmp->content);
			return (-1);
		}
		ft_strdel(&temp);
		tmp->content_size = tmp->content_size + res;
	}
	if (res < 0)
		return (-1);
	if (!tmp->content_size)
		return (0);
	return (i ? get_from_buffer(line, tmp, tmp->content_size - res + i) : \
		get_from_buffer(line, tmp, 0));
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*file_content;
	t_list			*tmp;
	size_t			i;
	int				res;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	if (!(tmp = ft_find_list(fd, &file_content)))
		return (-1);
	if (tmp->content_size && (i = ft_strichr(tmp->content, '\n')))
		return (get_from_buffer(line, tmp, i));
	if (!tmp->content)
		if (!(tmp->content = ft_strnew(0)))
			return (-1);
	res = ft_read_file(fd, tmp, line);
	return (res);
}
