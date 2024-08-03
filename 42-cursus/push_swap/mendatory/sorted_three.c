/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:48:12 by obelhami          #+#    #+#             */
/*   Updated: 2024/04/23 23:56:16 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	swap_rotate(t_stack_node **a)
{
	swap(a, "sa\n");
	rotate(a, "ra\n");
}

void	sorted_three(t_stack_node **a, int size)
{
	t_stack_node	*tmp;

	tmp = *a;
	if (size == 3)
	{
		if (tmp->nbr > tmp->next->nbr && tmp->nbr < tmp->next->next->nbr)
			swap(a, "sa\n");
		else if (tmp->nbr > tmp->next->nbr && tmp->nbr > tmp->next->next->nbr
			&& tmp->next->nbr < tmp->next->next->nbr)
			rotate(a, "ra\n");
		else if (tmp->nbr > tmp->next->nbr && tmp->nbr > tmp->next->next->nbr
			&& tmp->next->nbr > tmp->next->next->nbr)
		{
			swap(a, "sa\n");
			reverse_rotate(a, "rra\n");
		}
		else if (tmp->nbr < tmp->next->nbr && tmp->nbr > tmp->next->next->nbr
			&& tmp->next->nbr > tmp->next->next->nbr)
			reverse_rotate(a, "rra\n");
		else if (tmp->nbr < tmp->next->nbr && tmp->nbr < tmp->next->next->nbr
			&& tmp->next->nbr > tmp->next->next->nbr)
			swap_rotate(a);
	}
}
