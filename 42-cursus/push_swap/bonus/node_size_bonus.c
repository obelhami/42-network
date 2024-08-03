/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_size_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:35:54 by obelhami          #+#    #+#             */
/*   Updated: 2024/04/25 15:35:55 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap_bonus.h"

int	node_size(t_stack_node *lst)
{
	int				i;
	t_stack_node	*tmp;

	if (!lst)
		return (0);
	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
