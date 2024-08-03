/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:17:08 by obelhami          #+#    #+#             */
/*   Updated: 2024/04/24 18:17:10 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	space(char c)
{
	if (c == ' ' )
		return (1);
	return (0);
}

void	check_empty_arg(char **argv, char **array)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	while (argv[i])
	{
		j = 0;
		count = 0;
		while (argv[i][j])
		{
			if (digit(argv[i][j]))
				count++;
			j++;
		}
		i++;
	}
	if (count == 0)
	{
		free(array);
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	check_characters(char **argv, char **array)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] == '+' || argv[i][j] == '-') && (argv[i][j
					+ 1] >= '0' && argv[i][j + 1] <= '9') && (argv[i][j
					- 1] == ' ' || argv[i][j - 1] == '\0'))
				j++;
			if (!digit(argv[i][j]) && !space(argv[i][j]))
			{
				free(array);
				write(2, "Error\n", 6);
				exit(1);
			}
			j++;
		}
		i++;
	}
	check_empty_arg(argv, array);
}

void	check_args(int argc, char **argv, char **array)
{
	int		i;
	int		x;
	int		j;
	char	**split;

	i = 1;
	x = 0;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (split == NULL)
			exit(1);
		j = 0;
		while (split[j])
		{
			fill_array(array, split, j, x);
			x++;
			j++;
		}
		i++;
		ft_free(split);
	}
	array[x] = NULL;
	check_max_int(array);
}
