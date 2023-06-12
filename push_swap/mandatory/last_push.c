/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 09:02:07 by abelkace          #+#    #+#             */
/*   Updated: 2023/06/01 22:39:42 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_stack **stack)
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
			node->index = i;
			i++;
			node = node->next;
	}
	return (i_max);
}

void	last_push(t_stack **a, t_stack **b)
{
	int	size;
	int	i_max;

	while (*b)
	{
		i_max = find_max(b);
		size = ft_lstsize(*b);
		while ((*b) && ((*b)->index != i_max))
		{
			if (i_max < (size / 2))
				ft_rotate(b, "rb");
			else if (i_max >= (size / 2))
				ft_reverse_rotate(b, "rrb");
		}
		ft_push(b, a, "pa");
	}
}
