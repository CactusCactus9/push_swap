/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:20:56 by abelkace          #+#    #+#             */
/*   Updated: 2023/05/31 20:55:41 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_lstsize(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void	ft_swap(t_stack **stack)
{
	t_stack	*node;
	int		temp;
	int		size;

	size = ft_lstsize(*stack);
	if (size > 1)
	{
		node = *stack;
		temp = node->content;
		node->content = node->next->content;
		node->next->content = temp;
	}
}

void	ft_rotate(t_stack **stack)
{
	t_stack	*node;
	t_stack	*temp;

	if (ft_lstsize(*stack) <= 1)
		return ;
	temp = *stack;
	(*stack) = (*stack)->next;
	temp->next = NULL;
	node = *stack;
	while (node->next)
		node = node->next;
	node->next = temp;
}

void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*node;
	t_stack	*temp;

	if (!(*stack) || !((*stack)->next))
		return ;
	node = *stack;
	while (node->next->next)
		node = node->next;
	temp = node->next;
	node->next = NULL;
	temp->next = *stack;
	(*stack) = temp;
}

void	ft_push(t_stack **stack_src, t_stack **stack_dest)
{
	t_stack	*node;

	if (!*stack_src)
		return ;
	node = *stack_src;
	(*stack_src) = (*stack_src)->next;
	ft_lstadd_front(stack_dest, node);
}
