/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 23:58:22 by obelhami          #+#    #+#             */
/*   Updated: 2023/08/17 06:29:35 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_comb2(int a, int b);

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 99)
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_comb2(a, b);
			if (a < 98)
				write(1, ", ", 2);
		b++;
		}
	a++;
	}
}

void	ft_comb2(int a, int b)
{
	char	a1;
	char	a2;
	char	b1;
	char	b2;

		a1 = '0' + (a / 10);
		a2 = '0' + (a % 10);
		b1 = '0' + (b / 10);
		b2 = '0' + (b % 10);
	write(1, &a1, 1);
	write(1, &a2, 1);
	write(1, " ", 1);
	write(1, &b1, 1);
	write(1, &b2, 1);
}
