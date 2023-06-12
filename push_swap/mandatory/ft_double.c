/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:29:16 by abelkace          #+#    #+#             */
/*   Updated: 2023/06/01 10:46:21 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_double_swap(t_stack **a, t_stack **b, char *str)
{
	if (*a && *b)
	{
		ft_swap(a, "sa");
		ft_swap(b, "sb");
		ft_putstr(str);
	}
}

void	ft_double_rotate(t_stack **a, t_stack **b, char *str)
{
	if (*a && *b)
	{
		ft_rotate(a, "ra");
		ft_rotate(b, "rb");
		ft_putstr(str);
	}
}

void	ft_double_reverse_rotate(t_stack **a, t_stack **b, char *str)
{
	if (*a && *b)
	{
		ft_reverse_rotate(a, "ra");
		ft_reverse_rotate(b, "rb");
		ft_putstr(str);
	}
}
