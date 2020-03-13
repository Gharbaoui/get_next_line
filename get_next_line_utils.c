/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ghar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 00:35:55 by mel-ghar          #+#    #+#             */
/*   Updated: 2020/03/13 14:23:00 by mel-ghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		if_error(char **line, char **tmp, char **buffer, int fd)
{
	if (BUFFER_SIZE > 0)
		*buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!(*buffer) || !line || fd == -1 || BUFFER_SIZE <= 0)
		return (1);
	if (!(*tmp))
		*tmp = ft_calloc(1, 1);
	if (!(*tmp))
	{
		free(*buffer);
		return (1);
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2, int is_free)
{
	char	*all;
	int		a;
	int		b;
	int		c;

	a = ft_strlen(s1);
	b = ft_strlen(s2);
	if (!(all = ft_calloc(a + b + 1, 1)))
		return (NULL);
	c = -1;
	while (++c < a)
		all[c] = s1[c];
	c = -1;
	while (++c < b)
		all[c + a] = s2[c];
	free(s1);
	if (is_free)
		free(s2);
	return (all);
}

char	*ft_substr(char *str, int start, int len)
{
	int		i;
	char	*tmp;

	i = 0;
	str += start;
	if (!(tmp = ft_calloc(len + 1, 1)))
		return (NULL);
	while (str[i] && i < len)
	{
		tmp[i] = str[i];
		i++;
	}
	return (tmp);
}

char	*ft_strdup(char *str)
{
	char	*ptr;
	int		i;

	i = ft_strlen(str);
	if (!(ptr = ft_calloc(i + 1, 1)))
		return (NULL);
	i = -1;
	while (str[++i])
		ptr[i] = str[i];
	return (ptr);
}

int		handel_last_line(char **line, char **buff, char **tmp, int ret_read)
{
	char *to_free;

	to_free = *tmp;
	if (ret_read == 1)
	{
		*line = ft_substr(*tmp, 0, pos_nl(*tmp));
		*tmp = ft_strdup(*tmp + pos_nl(*tmp) + 1);
		free(to_free);
		free(*buff);
		return (1);
	}
	else if (!ret_read)
	{
		*line = ft_strdup(*tmp);
		free(*buff);
		free(to_free);
		*tmp = NULL;
		return (0);
	}
	free(*buff);
	free(*tmp);
	return (ret_read);
}
