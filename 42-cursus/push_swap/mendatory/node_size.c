/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:09:58 by obelhami          #+#    #+#             */
/*   Updated: 2024/04/23 23:39:33 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

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
