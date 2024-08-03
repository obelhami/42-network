/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tab_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:45:34 by obelhami          #+#    #+#             */
/*   Updated: 2024/04/24 21:45:37 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap_bonus.h"

int	*fill_tab(t_stack_node **a, int size)
{
	int				i;
	int				*tab;
	t_stack_node	*tmp;

	i = 0;
	tmp = *a;
	tab = malloc(sizeof(int) * size);
	while (tmp)
	{
		tab[i] = tmp->nbr;
		tmp = tmp->next;
		i++;
	}
	sort_tab(tab, size);
	return (tab);
}

void	sort_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	number;

	number = 0;
	i = 0;
	while (i < size)
	{
		j = i;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				ft_swap(&tab[i], &tab[j]);
				number++;
			}
			j++;
		}
		i++;
	}
}
