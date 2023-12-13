/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:07:18 by obelhami          #+#    #+#             */
/*   Updated: 2023/12/07 13:29:45 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putnbr(int n, int *nbr, int *count)
{
	long	nb;
	int		i;
	char	a;

	nb = n;
	if (nb < 0)
	{
		write(1, "-", 1);
		*count += 1;
		nb = -nb;
	}
	i = 1;
	while (nb / i >= 10)
		i = i * 10;
	while (i > 0)
	{
		a = '0' + (nb / i);
		write(1, &a, 1);
		*count += 1;
		nb = nb % i;
		i = i / 10;
	}
	*nbr += 1;
}
