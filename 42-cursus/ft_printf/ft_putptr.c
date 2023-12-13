/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:44:53 by obelhami          #+#    #+#             */
/*   Updated: 2023/12/07 14:33:53 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putptr(unsigned long number, char *base, int *nb, int *count)
{
	unsigned long	box;

	if (!number)
	{
		write(1, "(nil)", 5);
		*count += 5;
	}
	else
	{
		write(1, "0x", 2);
		*count += 2;
		box = 1;
		while (number / box >= 16)
		{
			box = box * 16;
		}
		while (box >= 1)
		{
			write(1, &base[number / box], 1);
			*count += 1;
			number = number % box;
			box = box / 16;
		}
	}
	*nb += 1;
}
