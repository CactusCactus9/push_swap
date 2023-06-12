/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 00:02:27 by abelkace          #+#    #+#             */
/*   Updated: 2023/06/01 18:48:23 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_i_max(t_stack **stack, int *i_max)
{
	if (*i_max == 0)
	{
		ft_rotate(stack, "ra");
		if ((*stack)->content > (*stack)->next->content)
			ft_swap(stack, "sa");
	}
	if (*i_max == 1)
	{
		ft_reverse_rotate(stack, "rra");
		if ((*stack)->content > (*stack)->next->content)
			ft_swap(stack, "sa");
	}
	else
	{
		if ((*stack)->content > (*stack)->next->content)
			ft_swap(stack, "sa");
	}
}

void	sort_three(t_stack **stack)
{
	int		max;
	t_stack	*node;
	int		i;
	int		i_max;

	i = 0;
	max = -2147483648;
	node = *stack;
	while (node)
	{
		if (max < node->content)
		{
			max = node->content;
			i_max = i;
		}
			i++;
			node = node->next;
	}
	find_i_max(stack, &i_max);
}
