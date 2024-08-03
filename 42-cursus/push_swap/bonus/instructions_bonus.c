/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:47:34 by obelhami          #+#    #+#             */
/*   Updated: 2024/04/24 21:47:39 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap_bonus.h"

void	swap(t_stack_node **a)
{
	t_stack_node	*tmp;

	if (*a && (*a)->next)
	{
		tmp = (*a)->next;
		(*a)->next = tmp->next;
		tmp->next = *a;
		*a = tmp;
	}
}

void	push(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*tmp;

	if (*b)
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = *a;
		*a = tmp;
	}
}

void	rotate(t_stack_node **a)
{
	t_stack_node	*tmp;
	t_stack_node	*tmp2;

	if (*a && (*a)->next)
	{
		tmp = *a;
		tmp2 = *a;
		*a = (*a)->next;
		while (tmp2->next)
			tmp2 = tmp2->next;
		tmp2->next = tmp;
		tmp->next = NULL;
	}
}

void	reverse_rotate(t_stack_node **a)
{
	t_stack_node	*tmp;
	t_stack_node	*tmp2;

	if (*a && (*a)->next)
	{
		tmp = *a;
		tmp2 = *a;
		while (tmp2->next->next)
			tmp2 = tmp2->next;
		tmp2->next->next = tmp;
		*a = tmp2->next;
		tmp2->next = NULL;
	}
}
