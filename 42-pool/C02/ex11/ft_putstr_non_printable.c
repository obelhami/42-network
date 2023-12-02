/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 22:55:26 by obelhami          #+#    #+#             */
/*   Updated: 2023/08/23 02:07:53 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	char	*hexadecimals;
	int		i;
	int		a;
	int		b;

	hexadecimals = "0123456789abcdef";
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			a = (unsigned char)str[i] / 16;
			b = (unsigned char)str[i] % 16;
			write(1, "\\", 1);
			write(1, &hexadecimals[a], 1);
			write(1, &hexadecimals[b], 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
