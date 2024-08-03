/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:25:52 by obelhami          #+#    #+#             */
/*   Updated: 2024/04/14 16:25:54 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	number_of_args(int argc, char **argv)
{
	int	i;
	int	j;
	int	size;

	i = 1;
	size = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (space(argv[i][j]) && argv[i][j + 1] != '\0')
				size++;
			j++;
		}
		size++;
		i++;
	}
	return (size);
}

void	check_double(t_stack_node **a)
{
	t_stack_node	*tmp;
	t_stack_node	*tmp2;

	tmp = *a;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->nbr == tmp2->nbr)
			{
				free_stack(a);
				write(2, "Error\n", 6);
				exit(1);
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

void	init_stack(t_stack_node **a, char **array)
{
	int				i;
	t_stack_node	*n_node;
	t_stack_node	*tmp;

	i = 0;
	while (array[i])
	{
		n_node = new_node(ft_atolong(array[i]), array);
		if (*a == NULL)
			*a = n_node;
		else
		{
			tmp = *a;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = n_node;
		}
		i++;
	}
	ft_free(array);
	check_double(a);
}

int	main(int argc, char **argv)
{
	char			**array;
	int				*tab;
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	array = malloc(sizeof(char *) * (number_of_args(argc, argv) + 1));
	if (!array)
		return (0);
	check_characters(argv, array);
	check_args(argc, argv, array);
	init_stack(&a, array);
	tab = fill_tab(&a, node_size(a));
	sorted_stack(&a, &b, node_size(a), tab);
	free(tab);
	free_stack(&a);
	return (0);
}
