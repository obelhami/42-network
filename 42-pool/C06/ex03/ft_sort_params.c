/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 22:14:12 by obelhami          #+#    #+#             */
/*   Updated: 2023/08/29 13:53:05 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(int ac, char **av)
{
	int	i;
	int	j;

	j = 1;
	while (j < ac)
	{
		i = 0;
		while (av[j][i] != '\0')
		{
			write (1, &av[j][i], 1);
			i++;
		}
		write(1, "\n", 1);
		j++;
	}
}

int	main(int ac, char **av)
{
	int		i;
	int		j;
	int		x;
	char	*box;

	j = 1;
	while (j < ac)
	{
		x = j + 1;
		while (x < ac)
		{
			i = 0;
			while (av[j][i] == av[x][i])
				i++;
			if (av[j][i] > av[x][i])
			{
				box = av[j];
				av[j] = av[x];
				av[x] = box;
			}
			x++;
		}
		j++;
	}
	ft_print(ac, av);
}
