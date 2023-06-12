/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 12:50:42 by abelkace          #+#    #+#             */
/*   Updated: 2023/05/31 20:55:21 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack	*ft_lstnew(int content)
{
	t_stack	*node;

	node = malloc (sizeof(t_stack));
	if (!node)
		error("Error\nAllocation failed");
	node->content = content;
	node->index = 0;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_back(t_stack **a, t_stack *new)
{
	t_stack	*node;

	if (*a == NULL)
	{
		*a = new;
		return ;
	}
	node = *a;
	while (node->next)
		node = node->next;
	node->next = new;
}

void	ft_node(t_stack **a, char	**tab)
{
	int		i;

	i = -1;
	while (tab[++i])
		ft_lstadd_back(a, ft_lstnew(ft_atoi(tab[i])));
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	t_stack	*node;

	node = *lst;
	new->next = node;
	*lst = new;
}

int	check_sorted(t_stack *a)
{
	bool	flag;

	flag = true;
	while (a && a->next != NULL)
	{
		if (a->content > a->next->content)
			flag = false;
		a = a->next;
	}
	if (flag == true)
		return (0);
	else
		return (1);
}
