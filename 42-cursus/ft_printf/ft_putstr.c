/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:07:07 by obelhami          #+#    #+#             */
/*   Updated: 2023/12/07 13:08:10 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putstr(const char *str, int *nb, int *count)
{
	int	i;

	if (!str)
	{
		write(1, "(null)", 6);
		*nb += 1;
		*count += 6;
		return ;
	}
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		*count += 1;
		i++;
	}
	*nb += 1;
}
