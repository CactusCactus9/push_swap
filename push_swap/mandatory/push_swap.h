/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:25:46 by abelkace          #+#    #+#             */
/*   Updated: 2023/06/01 18:35:06 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
	int				index;
}	t_stack;

void	ft_putstr(char *s);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
void	error(char	*str);
char	**ft_split(char const *s, char c);
long	ft_atoi(char *str);
char	*ft_join(int size, char **strs, char sep);
void	check_numbers(char	**tab);
void	only_numbers(char	**tab);
void	check_dup(char	**tab);
void	ft_node(t_stack **a, char	**tab);
void	ft_swap(t_stack **stack, char *str);
void	ft_rotate(t_stack **stack, char *str);
void	ft_reverse_rotate(t_stack **stack, char *str);
void	ft_push(t_stack **stack_src, t_stack **stack_dest, char *str);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	sort_three(t_stack **stack);
void	sort_five(t_stack **a, t_stack **b);
void	check_sorted(t_stack *a);
int		ft_lstsize(t_stack *lst);
void	make_table(t_stack *stack, int *tab);
void	sort_table(t_stack *stack, int *tab);
void	ft_lst_index(t_stack *stack, int *tab);
void	ft_order(t_stack	**a, t_stack **b, int size);
void	last_push(t_stack **a, t_stack **b);
void	check_empty_arg(char **str);

#endif