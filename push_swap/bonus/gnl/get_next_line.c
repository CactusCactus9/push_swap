/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 23:02:12 by abelkace          #+#    #+#             */
/*   Updated: 2023/05/08 17:01:09 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	d = (char *)dst;
	s = (const char *)src;
	i = 0;
	if (n && !d && !s)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

char	*ft_read(int fd, char *s)
{
	int		f;
	char	*buf;

	f = 1;
	buf = malloc((sizeof(char) * BUFFER_SIZE) + 1);
	if (!buf)
		return (NULL);
	while (f > 0 && newline_check(s) == 0)
	{
		f = read(fd, buf, BUFFER_SIZE);
		if (f == -1)
			return (free(buf), free(s), NULL);
		else if (f == 0)
			break ;
		buf[f] = '\0';
		s = str_join(s, buf);
	}
	free(buf);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s = ft_read(fd, s);
	line = before_newline(s);
	s = after_newline(s);
	return (line);
}
