/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:53:54 by obelhami          #+#    #+#             */
/*   Updated: 2023/08/28 13:26:58 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	labo(char *str)
{
	int	initial;
	int	variable;

	initial = 0;
	while (str[initial] != '\0')
	{
		if (str[initial] == '-' || str[initial] == '+')
			return (0);
		variable = initial + 1;
		while (str[variable] != '\0')
		{
			if (str[variable] == str[initial])
				return (0);
			variable++;
		}
		initial++;
	}
	return (initial);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		box;
	int		size_of_base;
	long	number;

	if (labo(base) == 0)
		return ;
	number = nbr;
	if (number < 0)
	{
		write(1, "-", 1);
		number = -number;
	}
	size_of_base = labo(base);
	box = 1;
	while (number / box >= size_of_base)
	{
		box = box * size_of_base;
	}
	while (box >= 1)
	{
		write(1, &base[number / box], 1);
		number = number % box;
		box = box / size_of_base;
	}
}
