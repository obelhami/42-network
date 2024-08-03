/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searching.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 22:33:33 by obelhami          #+#    #+#             */
/*   Updated: 2024/04/23 23:51:59 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	find_max_stack(t_stack_node **b)
{
	t_stack_node	*tmp;
	int				max;

	tmp = (*b);
	max = tmp->nbr;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->nbr > max)
			max = tmp->nbr;
		tmp = tmp->next;
	}
	return (max);
}

int	position_max_stack(t_stack_node **b)
{
	int				i;
	t_stack_node	*tmp;

	tmp = (*b);
	i = 0;
	while (tmp)
	{
		if (tmp->nbr == find_max_stack(b))
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	position_min_tab(t_index *index, t_stack_node **a, int size_tab)
{
	int				i;
	t_stack_node	*tmp;

	tmp = (*a);
	i = 0;
	while (tmp)
	{
		if (tmp->nbr <= index->tab[size_tab])
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (i);
}
