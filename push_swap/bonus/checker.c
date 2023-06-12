/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 22:57:17 by abelkace          #+#    #+#             */
/*   Updated: 2023/06/01 18:30:58 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_double_pointer(char **p)
{
	int	i;

	i = 0;
	while (p[i])
		free(p[i++]);
	free (p);
}

void	free_lst(t_stack **p)
{
	t_stack	*temp;

	while (*p)
	{
		temp = (*p)->next;
		free (*p);
		(*p) = temp;
	}
}

char	**ft_parsing(char **strs, int size)
{
	char	*temp;
	char	**tab;

	temp = ft_join(size, strs, ' ');
	tab = ft_split(temp, ' ');
	free(temp);
	check_numbers(tab);
	only_numbers(tab);
	check_dup(tab);
	return (tab);
}

int	main(int ac, char **av)
{
	char	**tab;
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		exit(0);
	check_empty_arg(&av[1]);
	tab = ft_parsing(&av[1], ac - 1);
	ft_node(&a, tab);
	free_double_pointer(tab);
	check_input(&a, &b);
	if (check_sorted(a) == 0 && !b)
		ft_putstr("OK");
	else
		ft_putstr("KO");
	free_lst(&a);
	free_lst(&b);
}
