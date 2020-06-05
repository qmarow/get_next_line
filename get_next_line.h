/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmarowak <qmarowak@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 12:41:15 by qmarowak          #+#    #+#             */
/*   Updated: 2020/05/29 10:43:37 by qmarowak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

typedef struct		s_list
{
	int				fd;
	char			*ostatok;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *src);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strchr(const char *str, int ch);
t_list				*new_list(int fd);
int					get_next_line(int fd, char **line);

#endif
