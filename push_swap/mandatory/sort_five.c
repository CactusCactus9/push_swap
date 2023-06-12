/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 00:35:22 by abelkace          #+#    #+#             */
/*   Updated: 2023/06/01 23:38:35 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_index(t_stack *stack)
{
	int	min;
	int	i_min;
	int	i;

	min = 2147483647;
	i_min = 0;
	i = 0;
	while (stack)
	{
		if (stack->content < min)
		{
			min = stack->content;
			i_min = i;
		}
		i++;
		stack = stack->next;
	}
	return (i_min);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int		i;
	int		j;
	int		i_min;

	j = 2;
	while (*a && j--)
	{
		i_min = get_index(*a);
		if (i_min <= ((ft_lstsize(*a)) / 2))
		{
			while (i_min--)
				ft_rotate(a, "ra");
			ft_push(a, b, "pb");
		}
		else if (i_min > ((ft_lstsize(*a)) / 2))
		{
			i = (ft_lstsize(*a)) - i_min;
			while (i--)
				ft_reverse_rotate(a, "rra");
			ft_push(a, b, "pb");
		}
	}
	sort_three(a);
	ft_push(b, a, "pa");
	ft_push(b, a, "pa");
}
