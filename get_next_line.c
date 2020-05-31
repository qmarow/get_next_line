/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmarowak <qmarowak@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 14:15:39 by qmarowak          #+#    #+#             */
/*   Updated: 2020/05/31 15:26:02 by qmarowak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int		full_residue(char **line, char **value, int fun, char *buf)
{
	char *pointer_n;
	char *tmp;
	
	if (!buf)
		buf = *value;
	if ((pointer_n = ft_strchr(buf, '\n')))
	{
		*pointer_n = '\0';
		if (fun)
			*line = ft_strdup(*value);
		tmp = *value;
		if (!(*value = ft_strdup(++pointer_n)))
			return (-1);
		free(tmp);
		return (1);
	}
	return (0);
}

int		cut_residue(char **line, char **ostatok)
{
	int flag;

	if (*ostatok)
	{
		if ((flag = (full_residue(line, ostatok, 1, NULL))))
		{
			if(flag == 1)
				return (1);
		}
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
		if ((*line = ft_strdup("")))
			return (0);
	}
	return (-1);
}

int		get_line(int fd, char **line, char **ostatok)
{
	char	buf[BUFFER_SIZE + 1];
	int		end_chr;
	char	*tmp;
	int		flag;

	if ((flag = cut_residue(line, ostatok)) == -1)
		return (-1);
	while (!flag && (end_chr = read(fd, buf, BUFFER_SIZE)))
	{
		buf[end_chr] = '\0';
		tmp = *line;
		if ((flag = (full_residue(line, ostatok, 0, buf))) == -1)
			return (-1);
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
	int				flag;
	char			*buf;

	buf = NULL;
	if (fd < 0 || !line || !(list = list ? list : new_list(fd)) || read(fd, buf, 0))
		return (-1);
	tmp = list;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			tmp->next = new_list(fd);
		tmp = tmp->next;
	}
	flag = get_line(tmp->fd, line, &tmp->ostatok);
	return ((flag == 1) ? 1 : ft_clear(&list, &tmp));
}
