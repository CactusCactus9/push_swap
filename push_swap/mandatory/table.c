/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:06:10 by abelkace          #+#    #+#             */
/*   Updated: 2023/05/30 16:56:55 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_table(t_stack *stack, int *tab)
{
	int	i;

	i = 0;
	while (stack)
	{
		tab[i++] = stack->content;
		stack = stack->next;
	}
}

void	sort_table(t_stack *stack, int *tab)
{
	int	i;
	int	j;
	int	temp;
	int	size;

	i = 0;
	size = ft_lstsize(stack);
	while (i < (size - 1))
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	ft_lst_index(t_stack *stack, int *tab)
{
	int		j;
	int		size;
	t_stack	*node;

	size = ft_lstsize(stack);
	j = 0;
	while (j < size)
	{
		node = stack;
		while (node)
		{
			if (node->content == tab[j])
			{
				node->index = j;
				break ;
			}
			node = node->next;
		}
		j++;
	}
}

void	ft_order(t_stack	**a, t_stack **b, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 15;
	if (size > 100)
		j = 42;
	while (*a)
	{
		if ((*a)->index < i)
		{
			ft_push(a, b, "pb");
			j++;
			i++;
		}
		else if ((*a)->index >= i && (*a)->index < j)
		{
			ft_push(a, b, "pb");
			ft_rotate(b, "rb");
			i++;
			j++;
		}
		else
			ft_rotate(a, "ra");
	}
}
