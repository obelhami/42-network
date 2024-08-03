/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:38:42 by obelhami          #+#    #+#             */
/*   Updated: 2024/04/25 11:07:12 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap_bonus.h"

static void	full_free2(t_stack_node **a, t_stack_node **b, int *tab, char *str)
{
	free_stack(a);
	free_stack(b);
	free(tab);
	write(1, str, ft_strlen(str));
	exit(0);
}

void	ft_checker(t_stack_node **a, t_stack_node **b, int *tab, int size)
{
	int		i;
	char	*line;

	line = NULL;
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		check_string(a, b, line, tab);
		free(line);
	}
	i = 0;
	while (i < size)
	{
		if (!*a)
			full_free2(a, b, tab, "KO\n");
		if (tab[i] != (*a)->nbr)
			full_free2(a, b, tab, "KO\n");
		rotate(a);
		i++;
	}
	full_free2(a, b, tab, "OK\n");
}
