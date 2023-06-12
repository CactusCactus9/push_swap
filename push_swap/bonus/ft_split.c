/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:59:44 by abelkace          #+#    #+#             */
/*   Updated: 2023/05/31 16:07:10 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	count_word(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char	**free_all(char **p, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(p[i]);
		i++;
	}
	free(p);
	return (NULL);
}

static int	count_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	l;
	char	*p;

	i = 0;
	if (!s)
		return (0);
	l = ft_strlen(s);
	if (start >= l)
		return (ft_strdup(""));
	if (len > l)
		len = l;
	if (len > l - start)
		len = l - start;
	p = (char *)malloc(len * sizeof(char) + 1);
	if (!p)
		return (0);
	while (i < len && start < l)
	{
		p[i] = s[start];
		i++;
		start++;
	}
	p[i] = '\0';
	return (p);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**p;
	int		j;

	if (s == NULL)
		return (NULL);
	p = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!p)
		return (0);
	j = 0;
	i = 0;
	while (j < count_word(s, c))
	{
		while (s[i] == c)
			i++;
		p[j] = ft_substr(s, i, count_len(s + i, c));
		if (!p[j])
			return (free_all(p, j));
		i += count_len(s + i, c);
		j++;
	}
	p[j] = NULL;
	return (p);
}
