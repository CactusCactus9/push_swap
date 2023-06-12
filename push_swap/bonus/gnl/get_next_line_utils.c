/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 00:44:35 by abelkace          #+#    #+#             */
/*   Updated: 2023/05/10 13:21:04 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*str_join(char *s, char *buf)
{
	int		len1;
	int		len2;
	char	*s3;

	if (!s)
	{
		s = malloc(1);
		if (!s)
			return (NULL);
		s[0] = '\0';
	}
	if (!buf)
		return (NULL);
	len1 = ft_strlen(s);
	len2 = ft_strlen (buf);
	s3 = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!s3)
		return (NULL);
	ft_memcpy(s3, s, len1);
	ft_memcpy(s3 + len1, buf, len2);
	s3[len1 + len2] = '\0';
	free (s);
	return (s3);
}

int	len_line(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

int	newline_check(char *buf)
{
	int	i;

	i = 0;
	if (!buf)
		return (0);
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*before_newline(char *s)
{
	int		i;
	char	*line;

	i = 0;
	if (!s)
		return (NULL);
	line = malloc(len_line(s) + 2);
	if (!line)
		return (NULL);
	while (s[i] != '\0' && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		line [i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*after_newline(char *buf)
{
	int		i;
	int		j;
	char	*d;

	j = 0;
	if (!buf)
		return (NULL);
	i = len_line(buf);
	if (buf[i] == '\0' || (buf[i] == '\n' && buf[i + 1] == '\0'))
		return (free(buf), NULL);
	else
	{
		while (buf[++i] != '\0')
			j++;
		d = malloc(j + 1);
		if (!d)
			return (NULL);
		i = len_line(buf) + 1;
		j = 0;
		while (buf[i] != '\0')
			d[j++] = buf[i++];
	}
	return (free(buf), d[j] = '\0', d);
}
