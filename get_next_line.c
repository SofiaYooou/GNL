/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laddie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:12:33 by laddie            #+#    #+#             */
/*   Updated: 2020/11/28 13:08:50 by laddie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		checker(char **line, char **buff, int bytes)
{
	char			*n;
	char			*temp;

	if (!bytes && !(*buff))
	{
		*line = ft_strdup("");
		return (0);
	}
	if ((n = ft_strchr(*buff, '\n')))
	{
		*n = '\0';
		temp = *buff;
		*line = ft_strdup(*buff);
		*buff = ft_strdup(n + 1);
		free(temp);
		return (1);
	}
	else
	{
		*line = ft_strdup(*buff);
		free(*buff);
		*buff = NULL;
		return (0);
	}
}

int		get_next_line(int fd, char **line)
{
	static char		*buff;
	char			*str;
	int				bytes;
	char			*n;
	char			*temp;

	if (!line || fd < 0 || BUFFER_SIZE < 1 ||
			(read(fd, 0, 0) < 0) || !(str = malloc(BUFFER_SIZE + 1)))
		return (-1);
	while ((bytes = read(fd, str, BUFFER_SIZE)))
	{
		if (bytes == -1)
		{
			free(str);
			return (-1);
		}
		str[bytes] = '\0';
		temp = buff;
		buff = ft_strjoin(buff, str);
		free(temp);
		if ((n = ft_strchr(buff, '\n')))
			break ;
	}
	free(str);
	return (checker(line, &buff, bytes));
}
