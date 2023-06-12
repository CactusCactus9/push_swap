/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:17:01 by abelkace          #+#    #+#             */
/*   Updated: 2023/06/01 17:57:28 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int		str_row;
	int		str_col;

	length = count_len(size, strs, sep);
	new = malloc (length + 1);
	if (!new)
		error("malloc error\n");
	i = 0;
	str_row = 0;
	while (i < length)
	{
		str_col = 0;
		while (strs[str_row] && strs[str_row][str_col])
			new[i++] = strs[str_row][str_col++];
		new[i++] = sep;
		str_row++;
	}
	new[--i] = '\0';
	return (new);
}
