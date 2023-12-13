/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:07:00 by obelhami          #+#    #+#             */
/*   Updated: 2023/12/07 13:33:45 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putunbr(unsigned int nb, int *nbr, int *count)
{
	int		i;
	char	a;

	i = 1;
	while (nb / i >= 10)
		i = i * 10;
	while (i > 0)
	{
		a = nb / i + '0';
		write(1, &a, 1);
		*count += 1;
		nb = nb % i;
		i = i / 10;
	}
	*nbr += 1;
}
