/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:40:30 by obelhami          #+#    #+#             */
/*   Updated: 2024/04/23 23:54:15 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sorted_from_b(t_stack_node **a, t_stack_node **b)
{
	while (*b)
	{
		if (find_max_stack(b) == (*b)->nbr)
			push(a, b, "pa\n");
		else if (position_max_stack(b) > node_size((*b)) / 2)
			reverse_rotate(b, "rrb\n");
		else
			rotate(b, "rb\n");
	}
}

void	push_rotate(t_stack_node **b, t_stack_node **a, char *str, int *i)
{
	push(b, a, str);
	rotate(b, "rb\n");
	(*i)++;
}

void	rra_ra(t_stack_node **a, t_index *index, int size_tab)
{
	if (position_min_tab(index, a, size_tab) > node_size(*a) / 2)
		reverse_rotate(a, "rra\n");
	else
		rotate(a, "ra\n");
}

void	sorted_algo(t_index *index, t_stack_node **a, t_stack_node **b,
		int range)
{
	int	i;
	int	size_tab;

	i = 0;
	while (*a)
	{
		if (i + range < index->size)
			size_tab = i + range;
		if ((*a)->nbr >= index->tab[i] && (*a)->nbr <= index->tab[size_tab])
		{
			push(b, a, "pb\n");
			if ((*b)->next && (*b)->nbr < (*b)->next->nbr)
				swap(b, "sb\n");
			i++;
		}
		else
		{
			if ((*a)->nbr <= index->tab[i])
				push_rotate(b, a, "pb\n", &i);
			else
				rra_ra(a, index, size_tab);
		}
	}
	sorted_from_b(a, b);
}

void	sorted_stack(t_stack_node **a, t_stack_node **b, int size, int *tab)
{
	t_index	*index;

	index = malloc(sizeof(t_index));
	if (!index)
		exit(write(2, "Error\n", 6));
	index->size = size;
	index->tab = tab;
	index->range = 0;
	if (size == 2)
		sorted_two(a, size);
	else if (size == 3)
		sorted_three(a, size);
	else if (size == 4 || size == 5)
		sorted_four_five(a, b);
	else if (size > 5 && size <= 30)
		sorted_algo(index, a, b, 3);
	else if (size > 30 && size <= 100)
		sorted_algo(index, a, b, 10);
	else if (size > 100 && size <= 500)
		sorted_algo(index, a, b, 30);
	else if (size > 500)
		sorted_algo(index, a, b, 39);
	free(index);
}
