/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 20:32:10 by abelkace          #+#    #+#             */
/*   Updated: 2023/06/01 18:40:13 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ordered_lst(t_stack **a, t_stack **b)
{
	int		*table;
	int		size;

	size = ft_lstsize(*a);
	if (size == 2)
		ft_swap(a, "sa");
	else if (size == 3)
		sort_three(a);
	else if (size == 5 || size == 4)
		sort_five(a, b);
	else
	{
		table = malloc((sizeof(int) * size) + 1);
		if (!table)
			error("Error\n allocation failed");
		make_table(*a, table);
		sort_table(*a, table);
		ft_lst_index(*a, table);
		ft_order(a, b, size);
		last_push(a, b);
		free(table);
	}
}

int	main(int ac, char **av)
{
	char	**tab;
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		exit (0);
	check_empty_arg(&av[1]);
	tab = ft_parsing(&av[1], ac - 1);
	ft_node(&a, tab);
	free_double_pointer(tab);
	check_sorted(a);
	ordered_lst(&a, &b);
	free_lst(&a);
}
