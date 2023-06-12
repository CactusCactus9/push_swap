/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:02:12 by abelkace          #+#    #+#             */
/*   Updated: 2023/05/31 19:10:13 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 		i++;
// 	return (i);
// }

char	*ft_strdup(const char *s1)
{
	size_t	l;
	size_t	i;
	char	*s2;

	i = 0;
	l = ft_strlen(s1) + 1;
	s2 = malloc(l * sizeof(char));
	if (!s2)
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s)
		write (1, s++, 1);
	write(1, "\n", 1);
}

void	error(char	*str)
{
	ft_putstr(str);
	exit(1);
}

long	ft_atoi(char *str)
{
	unsigned long	res;
	int				sign;

	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10 + *str - '0');
		if (res >= 9223372036854775807 && sign == 1)
			return (-1);
		else if (res > 9223372036854775807 && sign == -1)
			return (0);
		str++;
	}
	return (res * sign);
}
