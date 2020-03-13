/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ghar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 00:34:25 by mel-ghar          #+#    #+#             */
/*   Updated: 2020/03/13 14:22:57 by mel-ghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		get_next_line(int fd, char **line)
{
	static char		*tmp;
	char			*buff;
	int				ret;

	if (if_error(line, &tmp, &buff, fd))
		return (-1);
	if (pos_nl(tmp) != -1)
		return (handel_last_line(line, &buff, &tmp, 1));
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (pos_nl(buff) != -1)
			return (handel(line, &tmp, &buff));
		tmp = ft_strjoin(tmp, buff, 0);
	}
	return (handel_last_line(line, &buff, &tmp, ret));
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		handel(char **line, char **tmp, char **buff)
{
	*line = ft_strjoin(*tmp, ft_substr(*buff, 0, pos_nl(*buff)), 1);
	*tmp = ft_strdup(*buff + pos_nl(*buff) + 1);
	free(*buff);
	return (1);
}

void	*ft_calloc(int a, int b)
{
	char	*tmp;
	int		size;
	int		i;

	size = a * b;
	i = 0;
	if (!(tmp = malloc(size)))
		return (NULL);
	tmp[size - 1] = 0;
	return (tmp);
}

int		pos_nl(char *buff)
{
	int i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
