/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_four_five.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:52:30 by obelhami          #+#    #+#             */
/*   Updated: 2024/04/23 23:52:31 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	find_index(t_stack_node **a)
{
	t_stack_node	*tmp;
	int				min;
	int				i;

	i = 0;
	tmp = *a;
	min = tmp->nbr;
	while (tmp)
	{
		if (tmp->nbr < min)
			min = tmp->nbr;
		tmp = tmp->next;
		i++;
	}
	return (i);
}

static int	find_min(t_stack_node **a)
{
	int				min;
	t_stack_node	*tmp;

	tmp = *a;
	min = tmp->nbr;
	while (tmp)
	{
		if (tmp->nbr < min)
			min = tmp->nbr;
		tmp = tmp->next;
	}
	return (min);
}

void	sorted_four_five(t_stack_node **a, t_stack_node **b)
{
	while (node_size(*a) > 3)
	{
		if ((*a)->nbr == find_min(a))
			push(b, a, "pb\n");
		else if (find_index(a) > node_size(*a) / 2)
			reverse_rotate(a, "rra\n");
		else
			rotate(a, "ra\n");
	}
	sorted_three(a, node_size(*a));
	push(a, b, "pa\n");
	push(a, b, "pa\n");
}
