/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laddie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:26:00 by laddie            #+#    #+#             */
/*   Updated: 2020/11/28 12:42:21 by laddie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char*)s;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	if (str[i] == c)
		return (str + i);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		y;

	i = 0;
	y = 0;
	if (!s2)
		return (NULL);
	if (!s1)
		return ((ft_strdup(s2)));
	if (!(s3 = (char*)malloc(sizeof(char) *
					((ft_strlen(s1) + ft_strlen(s2)) + 1))))
		return (NULL);
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[y])
		s3[i++] = s2[y++];
	s3[i] = '\0';
	return (s3);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s1) + 1;
	s2 = (char *)malloc(sizeof(char) * len);
	if (!s2)
		return (0);
	while (len > 1)
	{
		s2[i] = s1[i];
		i++;
		len--;
	}
	s2[i] = '\0';
	return (s2);
}
