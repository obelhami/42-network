/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:10:39 by obelhami          #+#    #+#             */
/*   Updated: 2023/12/07 13:52:09 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_puthex(unsigned int number, char *base, int *nb, int *count)
{
	unsigned int		box;

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
	*nb += 1;
}
