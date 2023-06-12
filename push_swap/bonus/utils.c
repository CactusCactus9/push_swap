/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:26:04 by abelkace          #+#    #+#             */
/*   Updated: 2023/06/01 18:23:02 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_numbers(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		if ((tab[i][j] == '+' || tab[i][j] == '-') && \
			(tab[i][j + 1] >= '0' && tab[i][j + 1] <= '9'))
			j++;
		while (tab[i][j])
		{
			if (tab[i][j] < '0' || tab[i][j] > '9')
				error("Error");
			else
				j++;
		}
		i++;
	}
}

void	only_numbers(char **tab)
{
	int		i;
	long	number;

	i = 0;
	while (tab[i])
	{
		number = ft_atoi(tab[i++]);
		if (number > 2147483647 || number < -2147483648)
			error("Error");
	}
}

void	check_dup(char **tab)
{
	int	i;
	int	j;
	int	n1;
	int	n2;

	i = 0;
	j = i + 1;
	while (tab[i] && tab[j])
	{
		while (tab[j])
		{
			n1 = ft_atoi(tab[i]);
			n2 = ft_atoi(tab[j]);
			if (n1 == n2)
				error("Error");
			else
				j++;
		}
		i++;
		j = i + 1;
	}
}

void	check_empty_arg(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j] == ' ' || str[i][j] == '\t')
			j++;
		if (str[i][j] == '\0')
			error("Error");
		i++;
	}
}
