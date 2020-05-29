/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmarowak <qmarowak@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 16:47:52 by qmarowak          #+#    #+#             */
/*   Updated: 2020/05/28 09:07:18 by qmarowak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (*(s + i) != '\0')
		++i;
	return (i);
}

char		*ft_strdup(const char *src)
{
	char	*str;
	int		i;

	i = -1;
	str = (char*)malloc(sizeof(char) * (ft_strlen((char*)src) + 1));
	if (!str)
		return (NULL);
	while (*((char*)src + ++i) != '\0')
		*(str + i) = *(src + i);
	*(str + i) = '\0';
	return (str);
}

char		*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	int		i;
	int		a;

	i = -1;
	a = -1;
	if (!s1 || !s2)
		return (NULL);
	str = (char*)malloc(sizeof(char) *
	(ft_strlen((char*)s1) + ft_strlen((char*)s2) + 1));
	if (!str)
		return (NULL);
	while (*(s1 + ++i) != '\0')
		*(str + i) = *(s1 + i);
	while (*(s2 + ++a) != '\0')
		*(str + i++) = *(s2 + a);
	*(str + i) = '\0';
	return (str);
}

char		*ft_strchr(const char *str, int ch)
{
	int i;

	i = -1;
	while (*((char*)str + ++i))
	{
		if (*(str + i) == ch)
			return (((char*)str + i));
	}
	if (ch == '\0')
		return (((char*)str + i));
	return (NULL);
}

t_list		*new_list(int fd)
{
	t_list *list;

	if (!(list = malloc(sizeof(t_list))))
		return (NULL);
	if (!list)
		list->ostatok = NULL;
	else
		list->fd = fd;
	list->next = NULL;
	return (list);
}
