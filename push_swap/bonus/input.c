/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:15:33 by abelkace          #+#    #+#             */
/*   Updated: 2023/06/01 13:23:32 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	i = 0;
	if (n == 0)
		return (0);
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (p1[i] && p2[i] && (i < n - 1) && (p1[i] == p2[i]))
		i++;
	return (p1[i] - p2[i]);
}

void	ft_checks(t_stack **a, t_stack **b, char	*line)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		ft_swap(a);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		ft_swap(b);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ft_double_swap(a, b);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		ft_push(b, a);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		ft_push(a, b);
}

void	ft_other_checks(t_stack **a, t_stack **b, char *line)
{
	if (ft_strncmp(line, "ra\n", 3) == 0)
		ft_rotate(a);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		ft_rotate(b);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		ft_double_rotate(a, b);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		ft_reverse_rotate(a);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		ft_reverse_rotate(b);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		ft_double_reverse_rotate(a, b);
}

void	check_input(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if ((!ft_strncmp(line, "sa\n", 3)) || (!ft_strncmp(line, "sb\n", 3)) || \
			(!ft_strncmp(line, "ss\n", 3)) || (!ft_strncmp(line, "pa\n", 3)) || \
			(!ft_strncmp(line, "pb\n", 3)))
			ft_checks(a, b, line);
		else if ((!ft_strncmp(line, "ra\n", 3)) || (!ft_strncmp(line, "rb\n", 3)) \
			|| (!ft_strncmp(line, "rr\n", 3)) || (!ft_strncmp(line, "rra\n", 4)) \
			|| (!ft_strncmp(line, "rrb\n", 4)) || (!ft_strncmp(line, "rrr\n", 4)))
			ft_other_checks(a, b, line);
		else
			error("Error");
		free(line);
		line = get_next_line(0);
	}
	free (line);
}
