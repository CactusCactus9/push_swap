/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:17:01 by abelkace          #+#    #+#             */
/*   Updated: 2023/05/31 16:07:57 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	count_len(int size, char **strs, char sep)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (i < size && strs[i])
	{
		len = len + strlen(strs[i]);
		i++;
	}
	if (sep)
	len = len + (size - 1);
	return (len);
}

char	*ft_join(int size, char **strs, char sep)
{
	char	*new;
	int		length;
	int		i;
	int		j;
	int		x;

	length = count_len(size, strs, sep);
	new = malloc (length + 1);
	if (!new)
		error("malloc error\n");
	i = 0;
	j = 0;
	while (i < length)
	{
		x = 0;
		while (strs[j] && strs[j][x])
			new[i++] = strs[j][x++];
		new[i++] = sep;
		j++;
	}
	new[--i] = '\0';
	return (new);
}
