/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:29:16 by abelkace          #+#    #+#             */
/*   Updated: 2023/05/31 19:35:30 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_double_swap(t_stack **a, t_stack **b)
{
	if (*a && *b)
	{
		ft_swap(a);
		ft_swap(b);
	}
}

void	ft_double_rotate(t_stack **a, t_stack **b)
{
	if (*a && *b)
	{
		ft_rotate(a);
		ft_rotate(b);
	}
}

void	ft_double_reverse_rotate(t_stack **a, t_stack **b)
{
	if (*a && *b)
	{
		ft_reverse_rotate(a);
		ft_reverse_rotate(b);
	}
}
