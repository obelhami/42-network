/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:04:38 by obelhami          #+#    #+#             */
/*   Updated: 2023/08/31 14:33:17 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	a;

	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	a = 2;
	while (a <= nb / a)
	{
		if (a * a == nb)
			return (a);
		else
			a++;
	}
	return (0);
}
/*
#include<stdio.h>

int	main(void)
{
	printf("%d", ft_sqrt(2147483647));
}
*/
