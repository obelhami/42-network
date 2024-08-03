/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:47:55 by obelhami          #+#    #+#             */
/*   Updated: 2024/04/24 21:48:04 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap_bonus.h"

t_stack_node	*new_node(long content, char **array)
{
	t_stack_node	*node;

	node = malloc(sizeof(t_stack_node));
	if (!node)
	{
		ft_free(array);
		write(2, "Error\n", 6);
		exit(1);
	}
	node->nbr = content;
	node->next = NULL;
	return (node);
}
