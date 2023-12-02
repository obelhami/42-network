/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 03:43:05 by obelhami          #+#    #+#             */
/*   Updated: 2023/09/06 04:35:11 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

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

void	ft_show_tab(struct s_stock_str *par)
{
	int	j;

	j = 0;
	while (par[j].str != '\0')
	{
		ft_putstr(par[j].str);
		write(1, "\n", 1);
		ft_putnbr(par[j].size);
		write(1, "\n", 1);
		ft_putstr(par[j].copy);
		write(1, "\n", 1);
		j++;
	}
}
