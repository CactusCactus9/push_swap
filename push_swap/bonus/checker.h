/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:26:01 by abelkace          #+#    #+#             */
/*   Updated: 2023/06/01 18:35:16 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include "./gnl/get_next_line.h"

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
	int				index;
}	t_stack;

char	*get_next_line(int fd);
void	check_numbers(char **tab);
void	only_numbers(char **tab);
void	check_dup(char **tab);
char	**ft_split(char const *s, char c);
char	*ft_join(int size, char **strs, char sep);
int		ft_lstsize(t_stack *lst);
void	ft_swap(t_stack **stack);
void	ft_rotate(t_stack **stack);
void	ft_reverse_rotate(t_stack **stack);
void	ft_push(t_stack **stack_src, t_stack **stack_dest);
t_stack	*ft_lstnew(int content);
void	ft_node(t_stack **a, char	**tab);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
int		check_sorted(t_stack *a);
void	ft_lstadd_back(t_stack **a, t_stack *new);
void	error(char	*str);
char	*ft_strdup(const char *s1);
long	ft_atoi(char *str);
void	ft_putstr(char *s);
void	ft_double_swap(t_stack **a, t_stack **b);
void	ft_double_rotate(t_stack **a, t_stack **b);
void	ft_double_reverse_rotate(t_stack **a, t_stack **b);
void	check_input(t_stack **a, t_stack **b);
size_t	ft_strlen(const char *str);
void	check_empty_arg(char **str);

#endif