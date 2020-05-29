/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmarowak <qmarowak@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 09:01:52 by qmarowak          #+#    #+#             */
/*   Updated: 2020/05/28 09:03:23 by qmarowak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line_bonus.h"

int		full_residue(char **line, char **value, int fun, char *buf)
{
	char *pointer_n;

	if (!buf)
		buf = *value;
	if ((pointer_n = ft_strchr(buf, '\n')))
	{
		*pointer_n = '\0';
		if (fun)
			*line = ft_strdup(*value);
		if (!(*value = ft_strdup(++pointer_n)))
			return (-1);
		return (1);
	}
	return (0);
}

int		cut_residue(char **line, char **ostatok)
{
	if (*ostatok)
	{
		if ((full_residue(line, ostatok, 1, NULL)) == 1)
			return (1);
		else
		{
			if ((*line = ft_strdup(*ostatok)))
			{
				free(*ostatok);
				*ostatok = NULL;
				return (0);
			}
		}
	}
	else
	{
		if (*line = ft_strdup(""))
			return (0);
	}
	return (-1);
}

int		get_line(int fd, char **line, char **ostatok)
{
	char	buf[BUF_SIZE + 1];
	int		end_chr;
	char	*tmp;
	int		flag;

	if ((flag = cut_residue(line, ostatok)) == -1)
		return (-1);
	while (!flag && (end_chr = read(fd, buf, BUF_SIZE)))
	{
		buf[end_chr] = '\0';
		if ((flag = (full_residue(line, ostatok, 0, buf))) == -1)
			return (-1);
		tmp = *line;
		if (!(*line = ft_strjoin((const char*)*line, (const char*)buf)))
			return (-1);
		free(tmp);
	}
	return ((*ostatok == NULL) ? 0 : 1);
}

int		ft_clear(t_list **list, t_list **tmp)
{
	t_list *start;

	start = *list;
	while (start->next != *tmp)
	{
		if (start->next == NULL)
		{
			free(*list);
			*list = NULL;
			return (0);
		}
		start = start->next;
	}
	start->next = (*tmp)->next;
	free(*tmp);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static t_list	*list;
	t_list			*tmp;
	int				f;

	if ((read(fd, 0, 1)) == -1 && !(*line))
		return (-1);
	list = list ? list : new_list(fd);
	tmp = list;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			tmp->next = new_list(fd);
		tmp = tmp->next;
	}
	f = get_line(tmp->fd, line, &tmp->ostatok);
	return ((f == 1) ? 1 : ft_clear(&list, &tmp));
}