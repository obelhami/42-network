/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 10:29:09 by obelhami          #+#    #+#             */
/*   Updated: 2023/08/26 10:29:36 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);

void	negatif(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		write(1, "-", 1);
		nb = nb * (-1);
		ft_putnbr(nb);
	}
}

void	ft_putnbr(int nb)
{
	int		a;
	int		b;
	char	c;

	if (nb < 0)
	{
		negatif(nb);
	}
	else
	{
		a = 1;
		b = nb;
		while (b >= 10)
		{
			a = a * 10;
			b = b / 10;
		}
		while (a >= 1)
		{
			c = nb / a + '0';
			write(1, &c, 1);
			nb = nb % a;
			a = a / 10;
		}
	}
}
