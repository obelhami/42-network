/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_string_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:40:10 by obelhami          #+#    #+#             */
/*   Updated: 2024/04/25 11:05:36 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap_bonus.h"

void	rrr(t_stack_node **a, t_stack_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	swap(a);
	swap(b);
}

static void	full_free(t_stack_node **a, t_stack_node **b, char *line, int *tab)
{
	free_stack(a);
	free_stack(b);
	free(tab);
	free(line);
	exit(write(2, "Error\n", 6));
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
}

void	check_string(t_stack_node **a, t_stack_node **b, char *line, int *tab)
{
	if (!ft_strcmp(line, "sa\n"))
		swap(a);
	else if (!ft_strcmp(line, "sb\n"))
		swap(b);
	else if (!ft_strcmp(line, "ss\n"))
		ss(a, b);
	else if (!ft_strcmp(line, "pa\n"))
		push(a, b);
	else if (!ft_strcmp(line, "pb\n"))
		push(b, a);
	else if (!ft_strcmp(line, "ra\n"))
		rotate(a);
	else if (!ft_strcmp(line, "rb\n"))
		rotate(b);
	else if (!ft_strcmp(line, "rr\n"))
		rr(a, b);
	else if (!ft_strcmp(line, "rra\n"))
		reverse_rotate(a);
	else if (!ft_strcmp(line, "rrb\n"))
		reverse_rotate(b);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(a, b);
	else
		full_free(a, b, line, tab);
}
